#include <iostream>
#include <vector>

using namespace std;

struct Point
{
    int x, y;
};

bool solution(vector<Point> v_point)
{
    int signedArea = 0;
    for (int i = 0; i < 3; i++)
    {
        signedArea += (v_point[i].x * v_point[i + 1].y);
        signedArea -= (v_point[i].y * v_point[i + 1].x);
    }
    if (signedArea < 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> v_point(n + 2);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        v_point[i].x = x;
        v_point[i].y = y;
    }
    v_point[n + 1].x = v_point[1].x;
    v_point[n + 1].y = v_point[1].y;
    v_point[0].x = v_point[n].x;
    v_point[0].y = v_point[n].y;
    //for (auto x : v_point) {
    //    cout << x.x << " " << x.y << endl;
    //}
    bool flag = false;
    for (int i = 1; i < n + 1; i++) {
        vector<Point> temp_tri(4);
        temp_tri[0].x = v_point[i - 1].x; temp_tri[0].y = v_point[i - 1].y;
        temp_tri[1].x = v_point[i].x; temp_tri[1].y = v_point[i].y;
        temp_tri[2].x = v_point[i + 1].x; temp_tri[2].y = v_point[i + 1].y;
        temp_tri[3].x = v_point[i - 1].x; temp_tri[3].y = v_point[i - 1].y;
        if (solution(temp_tri)) {
            cout << i << endl;
            flag = true;
        }
    }
    if (!flag) cout << 0;
    return 0;
}
