//
// Created by endargon on 9/26/16.
//
template<unsigned int N >
class string {
public:
    T operator[]( int i ) const {
        check( i );
        return a[ i ];
    }

    T & operator[]( int i ){
        check( i );
        return a[ i ];
    }

private:
    char a[N+1];

    void check( int i ){
        if (( i < 0 ) || ( i >= N )){
            std::cout << "HELP!\n";
            while( true ){}
        }
    }

};

int main() {

}