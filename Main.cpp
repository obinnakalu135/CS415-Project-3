#include <iostream>
#include "EasyBMP_1.06/EasyBMP.h"
#include <vector>
#include <queue>
using namespace std;

//Vertex Object to store Start and End Point
struct Vertex{
    int x;
    int y;
};
bool isNeighbor(BMP Image, Vertex u, Vertex v){
    if(abs(u.x - v.x) + abs(u.y - v.y) == 1  && Image(u.x, u.y) != Image(v.x, v.y)){
        return true;
    }
    return false;
}

void Breath_First_Search(BMP Image,Vertex start, Vertex end ){
    queue<Vertex> Q; //Creates our queue
    vector<bool> visited(Image.TellWidth()*Image.TellHeight(), false);  //Creates our visited array
    vector<int> d(Image.TellWidth() * Image.TellHeight(), INT_MAX); //Creates our distance array
    vector<Vertex> prev(Image.TellHeight()*Image.TellWidth(),Vertex());

    //Starting Point
    Q.push(start);
    visited[start.y * Image.TellWidth() + start.x] = true;
    d[start.y * Image.TellWidth() + start.x] = 0;

    //BFS
    while(!Q.empty() && !visited[end.y * Image.TellWidth() + end.x]){
        Vertex u = Q.front();
        Q.pop();

        for (int dx = -1; dx < 1; ++dx){
            for (int dy = -1; dy < 1; ++dy){
                if (dx == 0 && dy == 0) {
                    continue;
                }
                Vertex v;
                v.x = u.x + dx;
                v.y = u.y +dy;

                if (v.x >= 0 && v.x < Image.TellWidth() && v.y >= 0 && v.y < Image.TellHeight() &&
                !visited[v.y * Image.TellWidth() +v.x] && isNeighbor(Image, u, v)){
                    visited[v.y * Image.TellWidth() + v.x] = true;
                    d[v.y * Image.TellWidth() + v.x] = d[u.y * Image.TellWidth() + u.x] +1;
                    prev[v.y * Image.TellWidth() + v.x] = u;
                    Q.push(v);
                }
            }
        }
    }
    if (visited[end.y * Image.TellWidth() + end.x]){
        Vertex v = end;
        while (v.x != start.x && v.y != start.y){
            Image(v.x, v.y)->Red = 255;
            Image(v.x, v.y)->Green = 0;
            Image(v.x, v.y)->Blue = 0;
            v = prev [v.y * Image.TellWidth() + v.x];
        }
        Image(start.x, start.y)->Green = 255;
        Image(start.x, start.y)->Red = 0;
        Image(start.x, start.y)->Blue = 0;

        //Create output image
        BMP newImg;
        //newImg.(Image);
        //newImg.DrawText(0,0, to_string(d[end.y * Image.TellWidth() + end.x, 12]));
        newImg.WriteToFile("output.bmp");
    }
    else{
        cout<< "Target was not found"<<endl;
    }
}


//void Best_First_Search(){}

int main(int argc, char* argv[]){
    BMP Image;
    Image.ReadFromFile(argv[1]);

    Vertex start;
    start.x = 0;
    start.y = 0;

    Vertex end;
    end.x = Image.TellWidth();
    end.y = Image.TellHeight();

    Breath_First_Search(Image, start, end);

    return 0;
}
