#include <iostream>
#include <vector>
using namespace std;
typedef struct
{
    int x;
    int y;
}Point;

#define N 10         //迷宫的大小
#define ENTER_X 0    //入口的位置（0，0）
#define ENTER_Y 0
#define EXIT_X N-1   //出口的位置(N-1,N-1)
#define EXIT_Y N-1


int Maze[N][N];        //定义一个迷宫，0表示通道，1表示不可走（墙或已走）
int paths;        //路径条数
vector<Point> Path;    //保存一条可通的路径
vector<Point> BestPath;    //保存最短的路径

bool First = true;    //标志，找到第一条路径

//初始化迷宫
void InitMaze()
{
    //简单起见，本题定义一个固定大小10*10的迷宫
    //定义一个迷宫，0表示通道，1表示墙(或不可走)
    int mz[10][10] = {
        { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1 }, //0
        { 1, 0, 0, 1, 1, 0, 0, 1, 0, 1 }, //1
        { 1, 0, 0, 1, 0, 0, 0, 1, 0, 1 }, //2
        { 1, 0, 0, 0, 0, 1, 1, 0, 0, 1 }, //3
        { 1, 0, 1, 1, 1, 0, 0, 0, 0, 1 }, //4
        { 1, 0, 0, 0, 1, 0, 0, 0, 0, 1 }, //5
        { 1, 0, 1, 0, 0, 0, 1, 0, 0, 1 }, //6
        { 1, 0, 1, 1, 1, 0, 1, 1, 0, 1 }, //7
        { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 }, //8
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 }  //9
        //   0 1 2 3 4 5 6 7 8 9
    };

    //复制到迷宫
    memcpy(Maze, mz, sizeof(mz));

    paths = 0;
}

//从(x,y)位置开始走；初始为(0,0)
void MazeTrack(int x, int y)
{
    ///////////////////////////////////////
    //当前点加入到路径
    Point p = { x, y };
    Path.push_back(p);
    Maze[x][y] = 1;         //设置为已走，不可走

    //cout<<"来到("<<x<<","<<y<<")"<<endl;

    ///////////////////////////////////////
    //如果该位置是出口，输出结果
    if (x == EXIT_X && y == EXIT_Y)
    {
        cout << "找到一条道路" << endl;
        paths++;

        //输出路径
        vector<Point>::iterator it;
        for (it = Path.begin(); it != Path.end(); ++it)
        {
            cout << "(" << it->x << "," << it->y << ") ";
        }
        cout << endl;

        //判断是否更优
        if (First)//如果是找到的第一条路径，直接复制到最优路径
        {
            for (it = Path.begin(); it != Path.end(); ++it)
            {
                BestPath.push_back(*it);
            }
            First = false;
        }
        else //不是第一条，则判断是否更短
        {
            //更短，复制到最优路径
            if (Path.size()<BestPath.size())
            {
                BestPath.clear();
                for (it = Path.begin(); it != Path.end(); ++it)
                {
                    BestPath.push_back(*it);
                }
            }
        }
    }

    ///////////////////////////////////////
    //判断(x,y)位置的上、下、左、右是否可走

    if ((x - 1) >= 0 && Maze[x - 1][y] == 0)//上(x-1,y)；存在且可走
    {
        MazeTrack(x - 1, y);
    }

    if ((x + 1)<N && Maze[x + 1][y] == 0)//下(x+1,y)；存在且可走
    {
        MazeTrack(x + 1, y);
    }

    if ((y - 1) >= 0 && Maze[x][y - 1] == 0)//左(x,y-1)；存在且可走
    {
        MazeTrack(x, y - 1);
    }

    if ((y + 1)<N && Maze[x][y + 1] == 0)//右(x,y+1)；存在且可走
    {
        MazeTrack(x, y + 1);
    }

    ///////////////////////////////////////
    //返回上一步
    Path.pop_back();
    Maze[x][y] = 0;         //设置为未走
}


int main(int argc, char* argv[])
{
    //初始化迷宫
    InitMaze();

        //显示迷宫
    for(int i=0;i<N;++i){
    for(int j=0;j<N;++j)
    cout<<Maze[i][j]<<"  ";
    cout<<endl;
    }

    //回溯法走迷宫
    MazeTrack(ENTER_X, ENTER_Y);

    //显示最优的路径
    cout << "可行路径总条数为" << paths << "；最优路径为" << endl;
    vector<Point>::iterator it;
    for (it = BestPath.begin(); it != BestPath.end(); ++it)
    {
        cout << "(" << it->x << "," << it->y << ") ";
    }
    cout << endl;


    getchar();
    return 0;
}
