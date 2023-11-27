{\rtf1\ansi\ansicpg1252\cocoartf2757
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fswiss\fcharset0 Helvetica-Bold;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 NAMA: Mohammad Ari Alexander Aziz\
NIM: 13222093\
FAKULTAS/JURUSAN: STEI-R/Teknik Elektro \
\
Program berjalan dalam satu file dimulai dengan deklarasi variabel, array, dan masing-masing fungsi lalu membuat output sebagai tampilan menu dengan percabangan. Array history dideklarasikan agar dapat menjalankan fungsi redo/undo dengan menyimpan data lokasi pada array. Fungsi lokasi() menampilkan nilai x dan y. Fungsi gerak menambahkan nilai x dan y dengan input dengan variabel deltaX dan deltaY lalu menyimpan nilai tersebut pada array History. Fungsi gerak_2 menghitung nilai deltaX dan deltaY sebagai perubahan lokasi dengan mengubah sudut ke dalam bentuk radian dan menghitungnya dengan rumus kecepatan x waktu x cos(radian) untuk deltaX dan kecepatan x waktu x sin(radian) untuk deltaY. Fungsi undo bekerja dengan mengurangi variabel indeks_history lalu menampilkannya dengan fungsi lokasi. Fungsi redo bekerja dengan menambah variabel indeks_history lalu menampilkannya dengan fungsi lokasi. \

\f1\b Fungsi save() dan load() hanya dapat bekerja di laptop pembuat program 
\f0\b0 karena direktori penyimpanan file dinyatakan secara eksplisit pada kode (karena pada macbook harus dinyatakan secara eksplisit), sehingga jika ingin menjalankannya di device lain maka harus mengganti direktori penyimpanan file pada kode. }