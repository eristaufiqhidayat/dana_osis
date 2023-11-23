<main class="main-content">
<section class="section" id="bg-aliceblue">

<div class="container-sm text-justify">
<p class="lead"><a href="https://net.detik.org/docs/mysql/mysql/perintah-perintah-dasar-mysql.html">Perintah dasar MySQL</a> lengkap untuk pemula yang ingin belajar MySQL. Perintah dasar MySQL sederhana dan sangat mudah dipahami, sehingga MySQL menjadi sistem database (DBMS) yang sangat populer digunakan dikalangan personal hingga perusahaan. Selain itu, MySQL banyak digunakan dikarenakan menggunakan lisensi GNU, dan perfomance cukup baik untuk menangani database dari ukuran kecil hingga database kelas perusahaan.</p>
<p class="lead">Jika dilihat dari kebutuhan hardware juga tidak terlalu extrim, MySQL bisa dijalankan pada spek komputer yang rendah sekalipun. Berdasarkan pengalaman penulis, komputer/laptop dengan RAM 128 MySQL sudah bisa digunakan, apalagi di zaman sekarang teknologi komputer sudah sangat maju pesat, mungkin spek komputer Anda sudah 10x lebih tinggi dari spek yang dibutuhkan MySQL. </p>
<p class="lead">Saat ini, MySQL salah satu DBMS yang menjadi pilihan para pelajar, pengembang perangkat lunak, kampus, hingga perusahaan.</p>
<p class="alert alert-info">Perintah dasar MySQL ini dijalankan di console MySQL, pada kasus ini login ke MySQL melalui terminal.</p>
<hr class="hr-dash my-7">
<h2 id="daftar_isi">7 Perintah dasar MySQL</h2>
<ul class="daftar_isi">
<li><a href="#database">Create Database</a></li>
<li><a href="#table">Create Table</a></li>
<li><a href="#insert">Insert</a></li>
<li><a href="#select">Select</a></li>
<li><a href="#update">Update</a></li>
<li><a href="#delete">Delete</a></li>
<li><a href="#procedure">Procedure</a></li>
</ul>
<hr class="hr-dash my-7">
<h2 id="database">Perintah MySQL Create Database</h2>
<p>Perintah dasar MySQL untuk membuat database.</p>
<pre class="line-numbers code-light"><code class="language-sql">create database dana_osis;
</code></pre>
<p>Jika perintah suskses dijalankan maka akan muncul pesan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
</code></pre>
<p>Lihat database yang sudah dibuat dengan perintah berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">show databases;
</code></pre>
<p>Anda akan melihat nama-nama database yang ada di server MySQL, sesuai hak akses user Anda:</p>
<pre class="line-numbers code-light"><code class="language-sql">+--------------------+
| Database           |
+--------------------+
| dana_osis          |
| information_schema |
| mysql              |
| performance_schema |
| phpmyadmin         |
| platform           |
+--------------------+
6 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="table">Perintah MySQL Create Table</h2>
<p>Untuk membuat tabel pada database, Anda harus memilih/berada di database tersebut terlebih dahulu. Berikut perintah untuk berpindah database :</p>
<p>Perintah menggunakan database <mark>use nama_database</mark>, lihat contoh berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">use dana_osis;
</code></pre>
<p>Berikut kita akan membuat tabel dengan nama <mark>Pengguna</mark> dan dua field <mark>PenggunaId,PenggunaNama</mark>. Dalam sebuah tabel harus memiliki field kunci, dimana field kunci ini akan diisi dengan data unik dengan kata lain value nya tidak boleh sama. </p>
<p><strong>Mengapa harus ada field kunci?</strong></p>
<p>Karena field kunci digunakan untuk memastikan record data pada tabel tidak ada yang sama dalam artian lain setiap record data memiliki identitas unik/pembeda dari record data yang lain.</p>
<pre class="line-numbers code-light"><code class="language-sql">
CREATE TABLE `siswa` (
  `id` int(10) NOT NULL,
  `nis` int(20) NOT NULL,
  `nama_depan` varchar(50) NOT NULL,
  `nama_keluarga` varchar(50) NOT NULL,
  `tgl_lahir` date NOT NULL,
  `alamat` varchar(200) NOT NULL,
  `telp` varchar(50) NOT NULL
)
</code></pre>
<p>Jalankan perintah berikut untuk melihat tabel yang sudah dibuat pada database tersebut:</p>
<pre class="line-numbers code-light"><code class="language-sql">show tables;
</code></pre>
<p>Anda akan melihat hasil seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">+-----------------+
| dana_osis       |
+-----------------+
| siswa           |
+-----------------+
1 row in set (0.00 sec)
</code></pre>
<p>Untuk melihat struktur tabel dan field tabel yang Anda buat, jalankan perintah berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">describe Pengguna;
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">
+--------------+-----------------+------+-----+---------+----------------+
| Field        | Type            | Null | Key | Default | Extra          |
+--------------+-----------------+------+-----+---------+----------------+
| id           | int(10)unsigned | NO   | PRI | NULL    | auto_increment |
| nis          | int(20)         | NO   |     | NULL    |                |
| nama_depan   | varchar(50)     | NO   |     | NULL    |                |
| nama_keluarga| varchar(50)     | NO   |     | NULL    |                |
| tgl_lahir    | date            | NO   |     | NULL    |                |
| alamat       | varchar(200)    | NO   |     | NULL    |                |
| telp         | varchar(50)     | NO   |     | NULL    |                |
+--------------+-----------------+------+-----+---------+----------------+
2 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="insert">Perintah MySQL Insert Data</h2>
<p>Database dan tabel sudah sukses kita buat, sekarang saat nya kita mencoba melakukan insert data ke tabel tersebut.</p>
<h5>Single data</h5>
<p>Untuk memasukan data ke tabel kita menggunakan perintah <mark>Insert Into</mark> dilanjutkan <mark>Nama Tabel</mark> selanjutnya <mark>Nama kolom</mark>, selanjutnya <mark>Nilai</mark>. Penrintah berikut artinya kita memasukan data ke tabel <mark>Pengguna</mark> dengan velue <mark>PenggunaId=1, PenggunaNama=Zaki</mark>. Urutan penulisan field/kolom dengan urutan Nilai/Value harus sesuai, tidak boleh terbalik.</p>
<pre class="line-numbers code-light"><code class="language-sql">insert into Pengguna (PenggunaId,PenggunaNama) values("1","Zaki");
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
</code></pre>
<p>Setiap tabel memiliki field kunci, dan pada field kunci tidak boleh ada nilai yang sama. Pada contoh ini kita menggunakan <mark>PenggunaId</mark> sebagai field kunci, maka value PenggunaId tidak boleh ada nilai yang sama. Contoh Nilai 1 sudah digunakan, maka untuk memasukan data baru, nilai 1 tidak boleh lagi digunakan/di masukan kedalam field kunci. Jika kita memasukan nilai yang sama maka database otomatis akan menolaknya.</p>
<h5>Multi data</h5>
<p>Berikut contoh insert data multi record, artinya dalam satu query kita bisa memasukan banyak record data.</p>
<pre class="line-numbers code-light"><code class="language-sql">insert into Pengguna (PenggunaId,PenggunaNama) values("2","Jhoni"),("3","Roni"),("4","Eka"),("5","Yono");
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 4 rows affected (0.00 sec)
Records: 4  Duplicates: 0  Warnings: 0
</code></pre>
<hr class="hr-dash my-7">
<h2 id="select">Perintah MySQL Select Data</h2>
<p>Sekarang kita melakukan select data dari tabel Pengguna,berikut contoh perintah select data</p>
<p>Perintah <mark>select *</mark> artinya menampilkan semua kolom dari tabel Pengguna:</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna;
</code></pre>
<p>Anda akan melihat hasil berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">
+----+-----+------------+---------------+------------+--------+------+
| id | nis | nama_depan | nama_keluarga | tgl_lahir  | alamat | telp |
+----+-----+------------+---------------+------------+--------+------+
|  1 |   1 | eris       | taufi         | 1973-03-24 | 5      | 6    |
+----+-----+------------+---------------+------------+--------+------+
1 row in set (0.000 sec)
</code></pre>
<p>Jika ingin menampilkan kolom tertentu saja maka ganti tanda (*) menjadi nama field. Lihat contoh berikut kita akan menampilkan kolom nama saja.</p>
<pre class="line-numbers code-light"><code class="language-sql">select PenggunaNama from Pengguna;
</code></pre>
<p>Hasil query akan terlihat seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">+--------------+
+------------+
| nama_depan |
+------------+
| eris       |
+------------+
5 rows in set (0.00 sec)
</code></pre>
<p>Untuk menampilkan data tertentu/filter menggunkan <mark>where</mark>. Misal kita akan menampilkan informasi pengguna yang memiliki Id 2.</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from siswa where nama_depan=1;
</code></pre>
<p>Maka hasilnya akan terlihat seperti berikut. Pengguna yang memiliki Id 2 bernama Jhoni.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| id | nama_depan |
-----+------------+
|  1 | eris       |
+----+------------+
1 row in set (0.00 sec)
</code></pre>
<p>Membatasi jumlah record data menggunakan <mark>limit</mark>, misal kita hanya ingin menampilkan jumlah data sebanyak 2 record saja.</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna limit 2;
</code></pre>
<p>Maka hasilnya akan terlihat seperti berikut. Data hanya ditampilkan sebanyak 2 record.</p>
<pre class="line-numbers code-light"><code class="language-sql">
+----+--------------+
| id | nama_depan   |
+----+--------------+
|  1 | eris         |
|  2 | dhanis       |
+----+--------------+
2 rows in set (0.00 sec)
</code></pre>
<p>Mengurut data menggunakan perintah <mark>order by</mark>, Mengurutkan data ada 2 jenis <mark>asc=A-Z (kecil ke besar)</mark> dan <mark>desc = Z-A (besar ke kecil)</mark>. Misal kita mengurutkan data berdasarkan PenggunaId secara DESC.</p>
<pre class="line-numbers code-light"><code class="language-sql">select * from Pengguna order by PenggunaId DESC;
</code></pre>
<p>Maka hasilnya akan terlihat seperti berikut. Data diurutkan berdasarkan PenggunaId secara DESC.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| id | nama_depan |
+----+------------+
|  2 | Dhanis     |
|  1 | eris       |
+------------+--------------+
5 rows in set (0.00 sec)
</code></pre>
<p>Silahkan Anda melakukan latihan dengan kasus-kasus lain, supaya lebih lancar dan mahir dalam menggunakan <a href="https://net.detik.org/docs/mysql/mysql/perintah-perintah-dasar-mysql.html">perintah-perintah dasar MySQL</a>.</p>
<hr class="hr-dash my-7">
<h2 id="update">Perintah MySQL Update Data</h2>
<p>Data yang sudah tersimpan suatu saat akan dibutuhkan perubahan/update data. Berikut perintah melakukan update data.</p>
<p>Misal kita akan melakukan update/perubahan nama pengguna dengan Id 2.</p>
<pre class="line-numbers code-light"><code class="language-sql">update Pengguna set PenggunaNama="eris aja" where PenggunaId=1
</code></pre>
<p>Anda akan melihat tampilan seperti berikut.</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
Rows matched: 1  Changed: 1  Warnings: 0
</code></pre>
<p>Jika Anda lakukan select ke tabel Pengguna maka nama pengguna dengan Id=1 sudah berubah menjadi <mark>eris aja</mark>.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          1 | eris aja     |
|          2 | Dhanis       |
+------------+--------------+
5 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="delete">Perintah MySQL Delete Data</h2>
<p>Perintah hapus data sangat sederhana, oleh karena nya Anda harus berhati-hati sebelum melakukan hapus data, sebab data yang sudah terhapus tidak dapat dikembalikan.<p>
<p>Misal kita akan melakukan hapus data dengan Id 5.</p>
<pre class="line-numbers code-light"><code class="language-sql">delete from Pengguna where id=2
</code></pre>
<p>Anda akan melihat tampilan seperti berikut:</p>
<pre class="line-numbers code-light"><code class="language-sql">Query OK, 1 row affected (0.00 sec)
</code></pre>
<p>Jika Anda lakukan select ke tabel Pengguna maka nama pengguna dengan Id=5 sudah hilang dari tabel pengguna.</p>
<pre class="line-numbers code-light"><code class="language-sql">+------------+--------------+
| PenggunaId | PenggunaNama |
+------------+--------------+
|          2 | dhanis       |
+------------+--------------+
4 rows in set (0.00 sec)
</code></pre>
<hr class="hr-dash my-7">
<h2 id="procedure">Perintah MySQL Create Procedure</h2>
<p>Berikut adalah perintah untuk membuat procedur dengan nama <mark>Pro_SelectPengguna</mark>, isi procedure ini hanya melakukan query select pada tabel Pengguna .</p>
<pre class="line-numbers code-light"><code class="language-sql">DROP PROCEDURE `Pro_SelectPengguna`;
CREATE DEFINER=`root`@`localhost` PROCEDURE `Pro_SelectPengguna`() NOT DETERMINISTIC NO SQL SQL SECURITY DEFINER 
BEGIN
select * from Pengguna;
END
</code></pre>
<p>Berikut adalah perintah untuk menjalankan procedur.</p>
<pre class="line-numbers code-light"><code class="language-sql">CALL `Pro_SelectPengguna`();
</code></pre>
<hr class="hr-dash my-7">
<p>Demikian artikel tentang perintah-perintah dasar MySQL, silahkan dikembangkan lebih banyak kasus sesuai kebutuhan Anda.</p> </div>
</section>
</main>
