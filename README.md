# 0.1v
Pradedame su funkcijomis, kurios atsitiktinai sugeneruoja pažymius ir automatiškai įrašo juos į rezultatus ir skaičiuoja vidurkį. Toliau duodame pasirinkimą įvesti pažymius rankinių būdu bei gauname studento informaciją: vardą, pavardę. Tada suskaičiuojame medianą ir išvedame visą informaciją.

# 0.2v
Duodame programai nuskaityti txt failą su studendų pažymiais, suskaičiuojame medianą bei vidurkį ir išsaugojame naujame txt faile rezultatus: Vardas, Pavardė, vidurkis, mediana.

# 0.3v
Leidžiama naudotojui pasirinkti, ar įvesti studento duomenis bei pažymius ranka, ar įkelti iš failo. Jeigu duomenis veda naudotojas, jis turi galimybę pasirinkti, ar įvesti pažymius pačiam, ar sugeneruoti automatiškai. Papildyta Try-catch funkcija bei sukurti headers'ai.

# 0.4v
Sugeneruojami sąrašai iš 1000, 10 000, 100 000, 1 000 000 ir 10 000 000 studentų bei pažymių, vėliau apskaičiuojamas vidurkis su mediana ir rezultatai išvedami į du atskirus failus: nuskriausti.txt (kai vidurkis < 5) ir kietiakai.txt (kai vidurkis > 5). Studentai surušiuoti pagal rezultatus.

# 0.5v
vector<data> pakeistas į list<vector> ir išmatuota failo nuskaitymo trukmė bei rūšiavimo, išvedimo į du atskirus failus(kietiakai.txt ir nuskriausti.txt) trukmė.

kompiuterio parametrai: 
AMD Ryzen 5 3500U with Radeon Vega Mobile Gfx     2.10 GHz
8 GB RAM
512 GB SSD

SPARTOS ANALIZĖ:

| Studentų skaičius | Failo su studentais nuskaitymas | Failo rūšiavimas ir išvedimas į dvi grupes |
|--------------------|------------------------------------|----------------------------------------------|
| 1 000                   | 0.0053995 s                                 | 0.0138256 s                                               |
| 10 000                 | 0.0502726 s                                 | 0.155001 s                                                 |
| 100 000               | 0.516876 s                                   | 1.50728 s                                                   |
| 1 000 000            | 5.98676 s                                     | 14.1559 s                                                   |
| 10 000 000          | 53.1483                                       | -                                                            |


# 1.0v
# Naudojimosi instrukcija
   Paleidus programą langelyje jums bus surašyti visi galimi pasirinkimai:
   
   • Įvesti studentų duomenis ranka ( Taip pat turėsite galimybę sugeneruoti pažymius automatiškai).
   
   • Įkelti duomenis iš failo ir išsaugoti rezultatus naujame faile kursiokai.txt.
   
   • Sugeneruoti automatiškai studentų failą(galėsite įvesti studentų skaičių) bei sugrupuoti juos sukūriant du naujus failus pagal tai, ar galutinis pažymys yra didesnis ar mažesnis už 5.
   
  Jeigu įvyks klaida nuskaitant failą arba įvedant duomenis, jums bus apie tai pranešta.
  Siūloma sekti nurodymus, kadangi kiekvieną kartą jums bus nurodyta, kaip sustabdyti įvedimą arba kartoti jūsų pasirinkimą. 

  
  
Buvo išbandytos dvi strategijos( pirmoji strategija buvo naudojama ankstesnėse versijose) bei išmatuoti studentų išvedimų ir rūšiavimo į dvi grupes laikai.

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
