**OEP Salamon Donát: Dokumentáció az 1.házi feladathoz**

Salamon Donát

[salamon.donat2@gmail.com](mailto:salamon.donat2@gmail.com)

**Feladat:**

Valósítsa meg az egész számokat tartalmazó „Blokk-mátrixtípust". Ezek n×n-es négyzetes mátrixok, amelyekben a nem nulla elemek két, a főátlóra illeszkedő négyzetes blokkban helyezkednek el. Az első blokk mérete legyen b1×b1, a másodiké b2×b2, ahol 1≤b1,b2≤n-1, valamint b1+b2=n. (A példában b1=4 és b2 =5.) A típus reprezentációjában a biztosan nulla értékű elemeket nem kell eltárolni. (A két blokkot akár két kisebb mátrixban is tárolhatjuk.) Implementálja önálló metódusként a mátrix i-edik sorának j-edik elemét visszaadó műveletet, valamint az összeadás és szorzás műveleteket, továbbá a mátrix (négyzetes alakú) kiírását!

**n=b1+b2**

**Blokk-mátrix típus:**

A feladat lényegében egy olyan n\*n-es mátrix ábrázolása, amelyben van két másik m\*m és v\*v-s mátrix.

**Típusérték-halmaz:**

Egész típusú számokat tartalmazó(\{0}), 2 négyzetes mátrixot kell ábrázolni. Amelyeket egy nagy négyzetes mátrixként írunk ki. És a maradék hely kitöltésére 0-kat használunk, amelyeket nem tárolunk el.

Formálisan: BlockM(b1,b2) = {b1 € Nn\*n, b2 € Nn\*n |∀ i,j €[1..b1], ∀ i,j€[1..b2]: ∀a1[i,j]€[1..100], ∀a2[i,j]€[1..100]

**Típus műveletek:**

1.Lekérdezés

Az n\*n-es mátrixnak kérdezzük le az i.sor j.pozícióján(i,j€[1..n]) lévő elemet(e=a[i,j]

Formálisan:

A : BlockM(n) × N×N×N

a i j e

Ef : ( a=a'^ i=i' ^ j=j'^ i,j€[1..n] )

Uf : ( Ef ^ e=a[i,j] )

2.Összeadás

Két mátrix összeadása: c:=a+b. Az összeadásban az mátrixok méreteik azonosak.

Formálisan:

A : BlockM(n) × BlockM(n) × BlockM(n)

a b c

Ef : ( a=a' ^ b=b')

Uf : ( Ef ^ ∀i,j€[1..n]: c[i,j]= ∑k=1..n && ∑l=1..n a[k,l] + b[k,l])

3.Szorzás

Két mátrix szorzata c:=a\*b. A szorzásban szereplő mátrixoknak a méreteik megegyeznek.

//ki kell még találni

A : BMatrix(n) × BMatrix (n) × BMatrix (n)

a b c

Ef : ( a=a'^ b=b')

Uf : ( Ef ^ ∀i,j€[1..n]: c[i,j]= ∑k=1..n a[i,k] \* b[k,j])

Reprezentáció:

Vektorokkal dolgoztam, tudtam, hogy a vektornak hány eleme lesz(b1\*b1+b2\*b2)

X X X X 0 0 0 0 0

X X X X 0 0 0 0 0 b1=4

X X X X 0 0 0 0 0 b2=5 ezeknek megfelelően lesz egy V vektor, ami 4\*4 + 5\*5 elemű

X X X X 0 0 0 0 0

0 0 0 0 X X X X X

0 0 0 0 X X X X X

0 0 0 0 X X X X X

0 0 0 0 X X X X X

0 0 0 0 X X X X X

**Implementáció:**

Konkrét elem visszaadása:

A „mátrixot" én egy V vektorral tároltam el az adatait, illetve jelöltem.

c:KapottParameter(sor) d:KapottParameter(oszlop)


c\<=n1&&d\<=n1 || c\>=n2&&d\>=n2

kiir:0

(ha a második teljesül)

kiir:vektor[((n1\*n1+((c-n2)\*n2)+d)-1)-n1]

(ha az első teljesül)

kiir: vektor[(((c-1)\*n1)+d)-1]

n1,n2 az alapmátrix b1,b2-je, a c,d pedig a metódus 2 paraméteres, és azok kapják meg a sor, oszlopot

Ha, c\<=n1&&d\<=n1, tehát, ha az első négyzetes mátrixban a, b1\*b1-esben vagyunk, akkor:

vektor[(((c-1)\*n1)+d)-1]

Ha, c\>=n2&&d\>=n2, tehát a második négyzetes mátrixban vagyunk a, b2\*b2-esben, akkor:

vektor[((n1\*n1+((c-n2)\*n2)+d)-1)-n1]

2 mátrix összege:

Az a vektorral jelölt A mátrix elemei, valamint b vektorral jelölt B mátrix elemeinek az összege a c vektorral jelölt C mátrix elemei lesznek. Összeadás előtt ellenőrizni kell, hogy a mátrix azonos méretűek.

∀i€[0..n-1]: c[i]:= a[i] + b[i]

2 mátrix szorzata:

Az a vektorral jelölt A mátrix elemei, valamint b vektorral jelölt B mátrix elemeinek a szorzata a c vektorral jelölt C mátrix elemei lesznek. Összeadás előtt ellenőrizni kell, hogy a mátrix azonos méretűek.

∀i€[0..n-1]: c[i]:= a[i] \* b[i]

**Tesztelési terv:**

**Az " Adott elem"-el ellátott case-eknél, azt ellenőriztem, hogy az adott helyen, az adott elem van.**

**Az "osszeg,, case-eknél azt néztem meg, hogy, ha a 2 mátrixot összeadom , akkor megnézem, hogy az adott helyen az összeg mátrix melyik eleme van**

**A "szorzat,, case-eknél pedig azt vizsgáltam,ha a 2 mátrixot összeszoroznám, akkor a keletkezett mátrixban az adott helyen, milyen érték található.**