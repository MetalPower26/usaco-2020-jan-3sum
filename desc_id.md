### Deskripsi
Diberikan sebuah _array_ $A$ berukuran $N$ dan $Q$ _query_. Pada setiap _query_, anda diberikan dua angka $l, r$ dan diminta mengeluarkan banyaknya tripel $l \leq i < j < k \leq r$ sehingga $A_i + A_j + A_k = 0$. 

### Batasan
- $1 \leq N \leq 5000$
- $1 \leq l_i \leq r_i \leq N$ untuk $1 \leq i \leq Q$
- $1 \leq Q \leq 10^5$
- $-10^6 \leq A_i \leq 10^6$

### Subsoal
1. (10 poin) $N, Q \leq 100$
2. (18 poin) $N \leq 500$
3. (29 poin) $N \leq 2000$
4. (43 poin) Tidak ada batasan tambahan

### Masukan
<pre>
N Q
A<sub>1</sub> A<sub>2</sub> ... A<sub>N</sub>
l<sub>1</sub> r<sub>1</sub>
l<sub>2</sub> r<sub>2</sub>
...
l<sub>Q</sub> r<sub>Q</sub>
</pre>

### Keluaran
Keluarkan $Q$ baris dengan baris ke-$i$ merupakan jawaban dari _query_ ke-$i$.

### Contoh Masukan
```
7 3
2 0 -1 1 -2 3 3
1 5
2 4
1 7
```

### Contoh Keluaran
```
2
1
4
```

### Penjelasan Contoh
Untuk _query_ yang pertama, ada dua tripel yang memenuhi, yaitu (2, 3, 4) dan (3, 4, 5).