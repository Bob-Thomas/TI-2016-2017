#include "hwlib.hpp"
#include <algorithm>

namespace target = hwlib::target;

namespace hwlib {
    class pin_fixed {
    public:
        pin_fixed(pin_out &pin, bool v) {
            pin.set(v);
        }
    };
};

// The OLED display is connected in a very funny way:
// the I2C pins are reversed, and two GPIO pins are
// (mis-) used as ground and power for the display.
// This works, and makes it very easy to connect the LCD,
// but don't take this as an advice to connect peripherals is this way
// unless you know very well what you are doing.
class oled_buffered_d18_d21 {
    target::pin_oc scl, sda;
    hwlib::i2c_bus_bit_banged_scl_sda i2c_bus;
    target::pin_out pin_gnd, pin_vcc;
    hwlib::pin_fixed pin_gnd_fixed, pin_vcc_fixed;

public:
    hwlib::glcd_oled_buffered oled;

    oled_buffered_d18_d21() :
            scl(target::pins::sda),
            sda(target::pins::scl),
            i2c_bus(scl, sda),
            pin_gnd(target::pins::d19),
            pin_vcc(target::pins::d18),
            pin_gnd_fixed(pin_gnd, 0),
            pin_vcc_fixed(pin_vcc, 1),
            oled(i2c_bus, 0x3c) { }
};

namespace hwlib {
    constexpr location operator/(const location &lhs, int rhs) {
        return location(lhs.x / rhs, lhs.y / rhs);
    }

}

constexpr hwlib::location square(const hwlib::location &lhs) {
    auto m = std::min(lhs.x, lhs.y);
    return hwlib::location(m, m);
}


constexpr double pow(double g, int n) {
    double result = 1;
    while (n > 0) {
        result *= g;
        --n;
    }
    return result;
}

constexpr double fac(int n) {
    double result = 1;
    while (n > 0) {
        result *= n;
        --n;
    }
    return result;
}

constexpr double sin(double a) {
    return
            a
            - pow(a, 3) / fac(3)
            + pow(a, 5) / fac(5)
            - pow(a, 7) / fac(7)
            + pow(a, 9) / fac(9)
            - pow(a, 11) / fac(11)
            + pow(a, 13) / fac(13)
            - pow(a, 15) / fac(15)
            + pow(a, 17) / fac(17);
}

constexpr double cos(double a) {
    return sin((3.14 / 2) - a);
}

constexpr double radians_from_degrees(int degrees) {
    return 2 * 3.14 * (degrees / 360.0);
}

template<int N, typename T>
class lookup_sin {
private:
    T values[N] = {0};
public:
    constexpr lookup_sin() {
        for (int i = 0; i < N; ++i) {
            values[i] = sin(radians_from_degrees(i));
        }
    }

    constexpr T get(int n) const {
        return values[n];
    }
};

template<int N, typename T>
class lookup_cos {
private:
    T values[N] = {0};
public:
    constexpr lookup_cos() {
        for (int i = 0; i < N; ++i) {
            values[i] = cos (radians_from_degrees(i));
        }
    }

    constexpr T get(int n) const {
        return values[n];
    }
};

int range(int degree, int r) {
    return (degree - r < 0) ? -1 * (r - degree) : degree - r;
}

constexpr auto sinusses = lookup_sin<360, double>();
constexpr auto cosinusses = lookup_cos<360, double>();

int main(void) {

    // kill the watchdog & wait for the PC console to start
    WDT->WDT_MR = WDT_MR_WDDIS;
    hwlib::wait_ms(500);

    auto hw = oled_buffered_d18_d21();
    auto &oled = hw.oled;
    int center_x = (oled.size.x + 1) / 2 + 5;
    int center_y = (oled.size.y + 1) / 2;
    int startClock = 0;
    target::pin_in hourButton(target::pins::d13);
    target::pin_in minuteButton(target::pins::d12);
    hwlib::circle(hwlib::location(center_x, center_y), 1).draw(oled);

    // draw hour indicators
    int x, y;
    for (int angle = 0; angle < 360; angle += 30) {
        x = (center_x) + (square(oled.size).x / 2 - 2) * sinusses.get(angle);
        y = (center_y) - (square(oled.size).x / 2 - 2) * cosinusses.get(angle);
        hwlib::circle(hwlib::location(x, y), 2).draw(oled);
    }

    //init hand variables could be made into a fancy class
    int secondX, secondY = 0;
    long long int second = 1000000;
    long long int secondTimer = hwlib::now_us();
    int currentSecond = 0;

    int minuteX, minuteY = 0;
    int currentMinute = 0;

    int hourX, hourY = 0;
    int currentHour = 12;

    long long int time = hwlib::now_us();
    hwlib::font_default_8x8 font;
    hwlib::window_ostream stream(oled, font);

    //main loop
    for (; ;) {
        if (!hourButton.get() && !minuteButton.get()) {
            startClock = !startClock;
        }
        else if (!hourButton.get()) {
            currentHour++;
        }
        else if (!minuteButton.get()) {
            currentMinute++;
        }
        if (currentSecond > 60) {
            currentSecond = 0;
            currentMinute++;
        }
        if (currentMinute > 60) {
            currentMinute = 0;
            currentHour++;
        }
        if (currentHour > 12) {
            currentHour = 1;
        }

        //draw the hands on based on the set time
        hwlib::line(hwlib::location(center_x, center_y), hwlib::location(hourX, hourY), hwlib::white).draw(oled);
        hourX = center_x + 15 * sinusses.get((currentHour * 30 == 360) ? 0 : currentHour * 30);
        hourY = center_y - 15 * cosinusses.get((currentHour * 30 == 360) ? 0 : currentHour * 30);
        hwlib::line(hwlib::location(center_x, center_y), hwlib::location(hourX, hourY)).draw(oled);

        hwlib::line(hwlib::location(center_x, center_y), hwlib::location(minuteX, minuteY), hwlib::white).draw(
                oled);
        minuteX = center_x + 20 * sinusses.get((currentMinute * 6 == 360) ? 0 : currentMinute * 6);
        minuteY = center_y - 20 * cosinusses.get((currentMinute * 6 == 360) ? 0 : currentMinute * 6);
        hwlib::line(hwlib::location(center_x, center_y), hwlib::location(minuteX, minuteY)).draw(oled);

        hwlib::line(hwlib::location(center_x, center_y), hwlib::location(secondX, secondY), hwlib::white).draw(
                oled);
        hwlib::circle(hwlib::location(secondX, secondY), 1, hwlib::white).draw(oled);
        secondX = center_x + 25 * sinusses.get(currentSecond * 6);
        secondY = center_y - 25 * cosinusses.get(currentSecond * 6);
        hwlib::line(hwlib::location(center_x, center_y), hwlib::location(secondX, secondY)).draw(oled);
        hwlib::circle(hwlib::location(secondX, secondY), 1).draw(oled);

        //if clock is started updated the second timer

        stream << ((currentHour - 10 < 0) ? "0" : "") << currentHour << ":" <<
        ((currentMinute - 10 < 0) ? "0" : "") << currentMinute << " \v";
        oled.flush();

        if (startClock) {
            time = hwlib::now_us();
            if (secondTimer + second < time) {
                secondTimer = time;
                currentSecond++;
            }
        }

    }

}