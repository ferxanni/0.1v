

Buvo išbandytos dvi strategijos bei išmatuoti studentų išvedimų ir rūšiavimo į dvi grupes laikai.

Pirmos strategijos laikai, kai yra sukurti du nauji failai ir studentai išvedami į du atskirus failus:

|Studentų skaičius |	Std::list	         |  Std::vector      |
|-------------------|-------------------|-----------------|
|1 000	             |  0.0213201 s	 |  0.0196587 s    |
|10 000	             |  0.275629 s	 |  0.249503 s      |
|100 000                |	1.93216 s 	 |  1.85773 s        |
|1 000 000	     |  23.2972 s	         |  20.697 s          |

Antros strategijos laikai, kai yra sukuriamas tik vienas failas "nuskriausti" studentams, kurių vidurkis yra mažesnis nei 5, o studentų faile lieka tik "Kietiakai":

|Studentų skaičius |  Std::list	         |  Std::vector    |
|--------------------|------------------|----------------|
|1 000	              |  0.0151825 s	 |  0.0172916 s  |
|10 000	              |  0.12492 s	 |  0.128855 s    |
|100 000	              |  1.35315 s	 |  1.25676 s      |
|1 000 000	      |  13.3071 s	 |  12.6215 s      |

