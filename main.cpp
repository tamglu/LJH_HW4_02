#include <QCoreApplication>
#include <iostream>
using namespace std;

int arr[26][2];


class Root
{
public:
    char* data;
    char d;
    Root()
    {

    }
    Root(char val)
    {
        d = val;
    }
     void pre(int x)
     {
         if (x < 0)
         {
             return;
         }
         cout << char(x + 65);
         pre(arr[x][0]);
         pre(arr[x][1]);
         return;
     }
     void in(int x)
     {
         if (x < 0) return;

         in(arr[x][0]);
         cout <<char( x + 65);
         in(arr[x][1]);

         return;
     }
     void post(int x)
     {
         if (x < 0) return;

         post(arr[x][0]);
         post(arr[x][1]);
         cout <<char( x + 65);

         return;
     }
};


class Right :public Root
{
public:
    Right()
    {

    }

};

class Left :public Root
{
public:
    Left()
    {

    }

};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Root root;
    Left left;
    Right right;
    int node = 0;
    cin >> node;
    char nod[10];
    root.data = new char[node];
    left.data = new char[node];
    right.data = new char[node];

    for (int i = 0; i < node; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> nod[j];
            if (nod[j] == '.')
            {
                nod[j] = '\0';
            }
        }
        root.data[i] = nod[0];
        left.data[i] = nod[1];
        right.data[i] = nod[2];
        arr[root.data[i] - 65][0] = left.data[i] - 65;
        arr[root.data[i] - 65][1] = right.data[i] - 65;
    }

    root.pre(0);
    cout << endl;
    root.in(0);
    cout << endl;
    root.post(0);
    cout << endl;

    return a.exec();
}
