#include <iostream>
#define maks 10
using namespace std;

struct Queue
{
    string Nama1;
    string Nik1;
    string Job1;

}Q[maks];
int front, rear;

void start()
{
    front = rear = -1;
}
 
bool Empty()
{
    if (rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Full()
{
    if (rear == maks - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Enqueue()
{
    string nama2;
    if (Full())
    {
        cout << "Antrian Penuh Boss\n";
    }
    else
    {    
        cout << "Search Name Employee : ";
        cin >> nama2;
        bool search = true;
        for(int i = head; i <=tail; i++)
        {
            if(kyn.Nama[i] == nama2)
            {
                cout << "Nama : "<<kyn.Nama[i]<<" Nik "<<kyn.Nik[i]<<" Position "<<kyn.Job[i];
                Q[i].Nama1 = kyn.Nama[i];
                Q[i].Nik1 = kyn.Nik[i];
                Q[i].Job1 = kyn.Job[i];
            }
            if(!search == false)
            {
                cout << "Data atau Nama yang anda cari tidak ditemukan";
            }
        }
    }
}



