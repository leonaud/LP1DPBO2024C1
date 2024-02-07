#include <bits/stdc++.h>
#include "DPR.cpp"

using namespace std;

#define all(a) a.begin(), a.end()

int main()
{

    string id, name, bidang, partai;

    vector<Human> listdpr;
    vector<string> nama;

    bool ok = true;
    int menu;

    cout << "Pilihan menu\n1. Tambah\n2. Ubah\n3. Hapus\n4. Tampil\n5. Keluar\n";
    do
    {
        cout << "Pilih Menu : \n";
        cin >> menu;

        if (menu == 1)
        {
            Human dpr;
            cin >> name >> id >> bidang >> partai;
            if (find(all(nama), name) != nama.end())
            {
                cout << "Sudah ada data.\n";
            }
            else
            {
                dpr.set_id(id);
                dpr.set_name(name);
                dpr.set_bidang(bidang);
                dpr.set_partai(partai);
                nama.push_back(name);
                listdpr.push_back(dpr);
            }
        }
        else if (menu == 2)
        {
            Human dpr;
            cin >> name >> id >> bidang >> partai;
            auto idx = find(all(nama), name);
            if (idx == nama.end())
            {
                cout << "Tidak ada data.\n";
            }
            else
            {
                auto index = distance(nama.begin(), idx);
                listdpr[index].set_name(name);
                listdpr[index].set_id(id);
                listdpr[index].set_bidang(bidang);
                listdpr[index].set_partai(partai);
            }
        }
        else if (menu == 3)
        {
            cin >> name;
            auto idx = find(all(nama), name);
            if (idx == nama.end())
            {
                cout << "Tidak ada data.\n";
            }
            else
            {
                nama.erase(idx);
                listdpr.erase(listdpr.begin() + distance(nama.begin(), idx));
            }
        }
        else if (menu == 4)
        {
            // system("cls");
            cout << "List Data Anggota DPR\n";
            for (int i = 0; i < listdpr.size(); i++)
            {
                cout << i + 1 << ". " << listdpr[i].get_name() << " " << listdpr[i].get_id() << " " << listdpr[i].get_bidang() << " " << listdpr[i].get_partai() << endl;
            }
            cout << endl;
        }
        else
        {
            ok = false;
        }

    } while (ok);

    return 0;
}