#include <cstdlib>
#include <iostream>
#include <mysql.h>
#include <mysqld_error.h>
using namespace std;

char HOST[]="localhost";
char USER[]="root";
char PASS[]="";
char DB[]="dana_osis";
MYSQL *obj;
MYSQL *conection;
MYSQL_RES *result;
MYSQL_DATA data;
MYSQL_ROW row;

using namespace std;

void tambahdata(){
    if(!(obj = mysql_init(0))){
         cout <<"error";   
    }else{
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,"INSERT INTO `siswa` (`id`, `nis`, `nama_depan`, `nama_keluarga`, `tgl_lahir`, `alamat`, `telp`) VALUES (NULL, '1', '2', '3', '4', '5', '6');");
        result = mysql_use_result(obj);
        mysql_close(obj);
    } 
}
void selectdata(){
    if(!(obj = mysql_init(0))){
         cout <<"error";   
    }else{
        conection = mysql_real_connect(obj,HOST,USER,PASS,DB,3306,NULL,0);
        mysql_query(obj,"select * from siswa");
        result = mysql_use_result(obj);
        while(row = mysql_fetch_row(result)){
           cout <<row[1]<<endl; 
        }
        mysql_close(obj);
    }
}
int main()
{
    int tambah;  
    selectdata();
    cout << "Tambah Data ?";
    cin >>tambah;
    if(tambah == 1){
        tambahdata();
    }
    system("PAUSE");
}
