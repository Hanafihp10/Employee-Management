#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <cstdlib>
#define max 10

using namespace std;
struct Operasional  //Sturuct SLL Statis
{
    string month;
    int nominal;
    Operasional* next;
};
struct Queue        //Struct Jobdesk(Tugas Karyawan)
{
    string Nama1[max];
    int Nik1[max];
    string Job1[max];
    string Task1[max];
} Q;
struct Karyawan     // Struct Menyimpan Data Karyawan
{
    string Nama[max];
    int Nik[max];
    string Job[max];
    string Task[max];
} kyn;
struct DataKaryawan // Struct simpan Resign Employee Data
{
    string Nama;
    int Nik;
    string Job;
} dataKaryawan[max];

int head, tail;

void begin()
{
    head = tail = -1;
}
bool isEmpty()
{
    if (tail == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool IsFull()
{
    if (tail == max - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}       //LIAA
void InKaryawan()   //Karyawan Masuk
{
    string nilai, nilai3;
    int nilai2;
    if (IsFull() == true)
    {
        cout <<endl<< "KARYAWAN PENUH WOI !";
    }
    else
    {   cout << "Enter the employee's name\t: ";
        cin >> nilai;
        cout << "Enter employee ID\t\t: ";
        cin >> nilai2;
        cout << "Position\t\t\t: ";
        cin >> nilai3;
        cout << "===============================================\n";
        cout <<endl;
        if (isEmpty() == true)
        {
            head = tail = 0;
            kyn.Nama[tail] = nilai;
            kyn.Nik[tail] = nilai2;
            kyn.Job[tail] = nilai3;
            cout << kyn.Nama[tail]<<" NIK " << kyn.Nik[tail] << " Position "  << kyn.Job[tail]<<" = Data input Succes"<<endl;  
        }
        else if (IsFull() == false)
        {
            tail++;
            kyn.Nama[tail] = nilai;
            kyn.Nik[tail] = nilai2;
            kyn.Job[tail] = nilai3;
            cout << kyn.Nama[tail]<<" NIK " << kyn.Nik[tail] << " Positon "  << kyn.Job[tail]<<" = Data input Succes"<<endl;
            
        }
    }
}
void OutKaryawan()  //Karyawan Resign
{
    if (isEmpty() == true)
    {
        cout << "Data empty!";
    }
    else
    {
        string nama;
        cout << "Enter the name of the employee who will be resigning: ";
        cin >> nama;
        bool found = false;

        for (int i = head; i <= tail; i++)
        {
            if (kyn.Nama[i] == nama)
            {
                cout <<endl << "Outgoing Data : " << kyn.Nama[i] << " With ID " << kyn.Nik[i] << " Position " << kyn.Job[i] << endl;

               // Simpan data karyawan yang dikeluarkan ke array
                dataKaryawan[i].Nama = kyn.Nama[i];
                dataKaryawan[i].Nik = kyn.Nik[i];
                dataKaryawan[i].Job = kyn.Job[i];

                /* Menggeser data karyawan setelah karyawan yang ditemukan ke posisi sebelumnya
                   dengan memperbarui array Nama, Nik, dan Job
                   Hal ini dilakukan untuk menghapus data karyawan yang dikeluarkan (resign) dari array */

                for (int j = i; j < tail; j++)  
                {
                    kyn.Nama[j] = kyn.Nama[j + 1];
                    kyn.Nik[j] = kyn.Nik[j + 1];
                    kyn.Job[j] = kyn.Job[j + 1];
                }
                // Mengurangi tail untuk menunjukkan bahwa satu karyawan telah dikeluarkan (resign)
                tail--;
                found = true;
                break;
            }
        }

        if (!found)
        {
            cout <<endl<< "{Employee with name " << nama << " was not found in Data}" << endl<<endl;
        }       
    }
    cout << endl<< "Press Enter for Confirmation...."<<endl;         
}//Hanafi 
void PrintDataKaryawan() //untuk mencetak karyawan resign
{
    cout << "|==========================================================================|\n";
    cout << "|                          Resigned Employee Data                          |\n";
    cout << "|==========================================================================|\n";
    cout << "|   NO               Name                 ID                    POSITION   |\n";
    cout << "|==========================================================================|\n";
    for (int i = 0; i < max; i++)
    {
        if (!dataKaryawan[i].Nama.empty())
        {
            cout << "    " << left << setw(11) << i << left << setw(26) << dataKaryawan[i].Nama << setw(14) << to_string(dataKaryawan[i].Nik) << right << setw(16) << dataKaryawan[i].Job << endl;
        }
    }
    cout << "===========================================================================\n";

    cout << endl;
    system("pause");
}       
void Input()
{
    int Pilih;

    while (true) {
        system("cls");
        cout << "===============================================\n";
        cout << "                INPUT Employee\n";
        cout << "===============================================\n";
        cout << "1. Employee Enters\n";
        cout << "2. Employee Leave\n";
        cout << "3. Back To Menu\n";
        cout << "===============================================\n";
        cout << "INPUT NUMBER [1...3] : ";
        cin >> Pilih;
        cout << "===============================================\n";

        switch (Pilih) {
            case 1:
                while (true) {
                   InKaryawan();

                    // Tambahkan kondisi untuk kembali input or keluar
                    char kembali;
                    cout <<endl << "input data more ? [y/n]: ";
                    cin >> kembali;
                    cout << "===============================================\n";
                    if (kembali == 'n' || kembali == 'N')
                        break;
                }
                break;

            case 2:
                OutKaryawan();
                break;

            case 3:
                return;  // Kembali dari fungsi Input() ke fungsi main()

            default:
                break;
        }
        system("pause");
    }
}           //PUTU
void Data() //OUTPUT data karyawan Resign yang disimpan di STURCT
{
    cout << "|==========================================================================|\n";
    cout << "|                             Employee Data                                |\n";
    cout << "|==========================================================================|\n";
    cout << "|   NO               Name                 ID                    POSITION   |\n";
    cout << "|==========================================================================|\n";
    
    for(int i = 1; i <= tail; i++)
    {
        cout << "    " << left << setw(11) << i << left << setw(26) << kyn.Nama[i] << setw(14) << kyn.Nik[i] << right << setw(16) <<kyn.Job[i]<<endl;
    }
    cout << "===========================================================================\n";
    system("pause");
}
int front, rear;    //Membuat Struktur Antrian Baru
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
    if (rear == max - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}           //Hanafi
void Enqueue()  //Menambahkan Tugas KARYAWAN        -Jendral
{
    string nama2;
    if (Full())
    {
        cout << "{Full duty boss...}\n";
    }
    else
    {
        system("cls");
        cout << "======================================\n";
        cout << "Search Name Employee : ";
        cin >> nama2;
        cout << "======================================\n";
        bool search = false;
        int index = -1;  // Indeks untuk menyimpan data karyawan yang ditemukan (-1 = data tidak ditemukan)
        for (int i = head; i <= tail; i++)
        {
            if (kyn.Nama[i] == nama2)
            {
                index = i;  // Simpan indeks data karyawan yang ditemukan
                cout << "Name\t\t: " << kyn.Nama[i] << endl;
                cout << "ID\t\t: " << kyn.Nik[i] << "\t\t{DATA FOUND!}\n";
                cout << "Position\t: " << kyn.Job[i] << endl;
                cout << "======================================\n";
                cout << "Task\t\t: ";
                cin >> Q.Task1[rear+1];
                cout << "======================================\n";
                cout << "{task added successfully}\n";
                search = true;
                break;
            }
        }
        if (search)
        {
            // Simpan data karyawan yang ditemukan ke variabel sementara
            string tempNama = kyn.Nama[index];
            int tempNik = kyn.Nik[index];
            string tempJob = kyn.Job[index];
            
            // Tambahkan data karyawan ke dalam antrian
            if (Empty())
            {
                front = rear = 1;
                Q.Nama1[rear] = tempNama;
                Q.Nik1[rear] = tempNik;
                Q.Job1[rear] = tempJob;
            }
            else if(!Full())
            {
                rear++;
                Q.Nama1[rear] = tempNama;
                Q.Nik1[rear] = tempNik;
                Q.Job1[rear] = tempJob;
            }
        }
        else
        {
            cout << "The data or name you are looking for was not found.....\n\n";
        }
    }
    system("pause");
    system("cls");
}
void Dequeue() //Penerapan FIFO 
{
    if (Empty())
    {
        cout << "Antrian Kosong\n";
    }
    else
    {   cout << "======================================\n";
        cout << "Data yang dihapus: \n";
        cout << "======================================\n";
        cout << "Name\t\t: " << Q.Nama1[front+1] << endl;
        cout << "ID\t\t: " << Q.Nik1[front+1] << endl;
        cout << "Position\t: " << Q.Job1[front+1] << endl;
        cout << "Task\t\t: " << Q.Task1[front+1] << endl;
        cout << "======================================\n";
        
        // Geser elemen-elemen antrian ke depan
        for (int i = front; i < rear; i++)
        {
            Q.Nama1[i] = Q.Nama1[i + 1];
            Q.Nik1[i] = Q.Nik1[i + 1];
            Q.Job1[i] = Q.Job1[i + 1];
            Q.Task1[i] = Q.Task1[i + 1];
        }
        
        // Kurangi nilai rear
        rear--;
        
        if (Empty())
        {
            // Set front dan rear ke kondisi awal jika antrian kosong
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }
    system("pause");
    system("cls");
}
void Cost() //SLL Statis
{     system("cls");
      cout << "=================================================\n";
      cout << "             MONTHLY OPERATING COST\n";
      cout << "=================================================\n";
    Operasional* head = NULL;

        // Menambahkan pengeluaran bulanan
        Operasional* node1 = new Operasional;
        node1->month = "Januari";
        node1->nominal = 12500000;
        node1->next = NULL;
        head = node1;

        Operasional* node2 = new Operasional;
        node2->month = "Februari";
        node2->nominal = 15000000;
        node2->next = NULL;
        node1->next = node2;

        Operasional* node3 = new Operasional;
        node3->month = "Maret";
        node3->nominal = 12000000;
        node3->next = NULL;
        node2->next = node3;

        Operasional* node4 = new Operasional;
        node4->month = "April";
        node4->nominal = 18000000;
        node4->next = NULL;
        node3->next = node4;

        Operasional* node5 = new Operasional;
        node5->month = "Mei";
        node5->nominal = 9000000;
        node5->next = NULL;
        node4->next = node5;

        Operasional* node6 = new Operasional;
        node6->month = "Juni";
        node6->nominal = 13000000;
        node6->next = NULL;
        node5->next = node6;

    // Menampilkan pengeluaran bulanan
    Operasional* cur = head;
    cout << left << setw(12) << "Bulan" << "Jumlah Pengeluaran (IDR)" << endl;
    cout << "----------------------------------------------" << endl;
    while (cur != NULL) {
        cout << left << setw(12) << cur->month << "Rp " << setw(18) << cur->nominal << endl;
        cur = cur->next;
    }
    system("pause");        //Jendral
}
void QueueData() //Data yang ada ada di QUEUE   -ULFAA
{   system("cls");
    cout << "|======================================================================================|\n";
    cout << "|                                   Task Data                                          |\n";
    cout << "|======================================================================================|\n";
    cout << "|  NO               Name              ID               POSITION                TASK    |\n";
    cout << "|======================================================================================|\n";
    for (int i = 1; i <= rear; i++)
    {
        cout << "  " << left << setw(8) << i << right << setw(14) << Q.Nama1[i] <<right<<setw(17)<<Q.Nik1[i]<<right<<setw(20)<<Q.Job1[i]<<setw(22)<<Q.Task1[i]<<endl;
    }
    cout << "|======================================================================================|\n";

    system("pause");          
}
void JobDesk()          
{  
    int Pilih;
    
    while(true)
    {
    cout << "|==========================================================================|\n";
    cout << "|                              JOBDESK                                     |\n";
    cout << "|==========================================================================|\n";
    cout << "|1. Enter Assignment                        <- Input Teks Employee         |\n";
    cout << "|2. Dequeue Assignment                      <- FIFO                        |\n";
    cout << "|3. Queue Data                              <- Data Process                |\n";
    cout << "|4. Back Menu                               <- Back in Menu Main           |\n";
    cout << "|==========================================================================|\n";
    cout << " Choose Number[1....4] : ";cin >> Pilih; 
   switch (Pilih)
        {
            case 1:
                Enqueue();
                break;
            case 2:
                if (!Empty()) {
                    Dequeue();
                } else {
                    cout << "No assignment available.\n";
                }
                break;
            case 3:
                QueueData();
                break;
            case 4:
                return;
                break;
            default:
                break;
        }
    }
    system("cls");
}
int main()
{
    int Pilih;
    bool running = true;  // Variabel boolean untuk mengontrol perulangan while

    while (running) {
        system("cls");
        cout << "|==========================================================================|\n";
        cout << "|                    Employee Management Program c++                       |\n";
        cout << "|==========================================================================|\n";
        cout << "|1. In/Out Employee Data               <- entry and exit of employee data  |\n";     
        cout << "|2. Employee Jobdesk                   <- Jobs                             |\n";
        cout << "|3. Employee Data                      <- Position                         |\n";
        cout << "|4. Resigned Employee Data             <- Resign                           |\n";
        cout << "|5. Operating costs                    <- Money Out                        |\n";
        cout << "|6. Exit Program                                                           |\n";
        cout << "|==========================================================================|\n";
        cout << " Choose Number [1....5] : "; cin >> Pilih;  
        cout << "|==========================================================================\n";

        system("cls");

        switch (Pilih)
        {
            case 1:
            Input();
            break;
    
        case 2:
            JobDesk();
            break;
        case 3:
            Data();
            break;
    
        case 4:
            PrintDataKaryawan();
            break;
        case 5 :
            Cost();
            break;
        case 6:
            return 0;
            break;

        default:
            running = false;  // Jika pilihan selain 1-5, hentikan perulangan while
            break;
        }
    }

    return 0;
}                   //ULFAA

