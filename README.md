# Programozas-II
 A Neumann János Egyetem mérnökinformatikus BSc hallgatói számára készült órai anyagok a Programozás II. című tárgyhoz!

## 1. labor
 Az első labor keretein belül átismételtük, hogy mit tanultunk az előzmény tárgy során. Megoldottunk egy stringekkel kapcsolatos feladatot, valamint egy ZH-hoz haosnlító példát ismétlésképpen.
>[!NOTE]
Gyakorláshoz feltöltöttem az [1. labor](https://github.com/Gyuri02917/Programozas-II/tree/main/1.%20labor) mappába egy [gyakorlas.pdf](https://github.com/Gyuri02917/Programozas-II/blob/main/1.%20labor/gyakorlas.pdf)-et, valamint az ahhoz szükséges forrásállományt is. Aki elkészíti a feladatot, hozza magával a következő gyakorlatra, és jelezze felém, hogy készült házi feladattal.

## 2. labor
 A második labor alkalmával megismerkedtünk a vektorral. Megismertük, hogy a vektor szabadon bővíthető bizonyos keretek között. Ezek után megnéztük, hogy hogyan használhatjuk a dinamikus változókat, és a dinamikus tömböket. Végül pedig megtanultuk a parancssori argumentum használatát.
 >[!NOTE]
 Gyakorlásképpen az [1. labor](https://github.com/Gyuri02917/Programozas-II/tree/main/1.%20labor) mappában található [gyakorlas.pdf](https://github.com/Gyuri02917/Programozas-II/blob/main/1.%20labor/gyakorlas.pdf) feladatait kell elkészíteni (1-4. feladat). Most ne statikus tömböt vagy struktúra tömböt alkalmazzon, hanem dinamikus tömböket. Ha ezzel elkészült, készítse el vektor használatával is.
 
 >[!WARNING]
 Ha Visual Studiot használ a futtatáshoz, előfordulhat, hogy nem engedi futtatni 'Stack Overflow' hibával. Ebben az esetben az órán is bemutatott módon állítsa a verem méretét nagyobbra. Például: `/F 1073741824` Ezt megteheti a Project > Properties > C/C++ > Command Line > Additional Options >  /F 1073741824. Ezzel ~1Gb stack méretet adunk a futtatáshoz. Lehet ettől kisebb méretet is használni, ez egy eléggé nagy túlzás, de garantált a futás. Valamint a `Ctrl+F5` álltali futtatás javasolt, mert `F5` esetén nem mindig fogadja el a módosított stack méretet.

## 3. labor
 A harmadik labor alkalmával megtanultuk a függvények típusait, az argumentumok és paraméterek jelentését, valamint ezek használatát. Ezeken felül gyakoroltuk a dinamikus tárkezelést.
 >[!NOTE]
 A `void` típusú függvénynek nem szabad visszatérési értéket `return` adni! Hibát fog jelezni a fordító! Ezen felül minden más tanult típushoz szükséges a `return` ág, mint visszatérési érték!