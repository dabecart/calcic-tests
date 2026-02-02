struct PointInformation {
    const char* const location;
    const char* quality;
};

struct Point {
    float x;
    float y;
    struct PointInformation info;
};

int main() {
    const char* loc = "Look behind you";
    const char* qual = "yep";
    struct Point p = {10, 5, {loc, qual}};
    p.x = 11.0f;
    p.y = 10;
    p.info.location = qual;
    return 0;
}