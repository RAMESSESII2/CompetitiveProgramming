#include<iostream>
    
using namespace std;
void file_i_o(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("cerr.txt", "w", stderr);
#endif
}

struct Vector2{
    float x, y;
    Vector2(float x, float y)
        : x(x), y(y) {}
    Vector2 Add(const Vector2& other) const{ 
        return Vector2(x + other.x, y + other.y);
    }
    Vector2 operator +(const Vector2& other)const{ 
        return Add(other);
    }

    Vector2 operator *(const Vector2& other) const{ 
        return Vector2(x*other.x, y * other.y);
    }
    Vector2 Multiply(const Vector2& other) const{ 
        return *this*other;
        // return operator*(other);
    }

    bool operator==(const Vector2& other) const{ 
        return x == other.x && y == other.y;
    }
    bool operator!=(const Vector2& other) const{ 
        // return !(x == other.x && y == other.y);
        // return !operator==(other);
        return !(*this == other);
    }
};
//overloading cout << 
std::ostream& operator<<(std::ostream& stream, const Vector2& other){
    stream << other.x << " " << other.y << endl;
    return stream;
}

int main(){
    file_i_o();

    Vector2 position(4.0f, 4.0f);
    Vector2 speed(0.5f, 1.5f);
    Vector2 result = position.Add(speed);
    cout<< result.x << " " << result.y << endl;

    Vector2 powerup(1.1f, 1.1f);
    // Vector2 res = position.Add(speed.Multiply(powerup));
    Vector2 res = position+speed*powerup;
    cout<< res.x << " " << res.y << endl;

    Vector2 fivetimes(5, 5);
    cout << (speed*fivetimes).x << endl;
    cout << (speed.Multiply(fivetimes)).y << endl;

    cout << speed*fivetimes << endl;

    cout << (res == result) << endl;

    return 0;
}
