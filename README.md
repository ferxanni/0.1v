# Naudojimosi instrukcija
• Įsijungus programai matysite, jog galite įvesti studentų skaičių, kad sugeneruoti duomenų sąrašą automatiškai
  • įvesite 1000, 10 000, 100 000, 1 000 000, 10 000 000(Nerekomenduojama, nes programa gali "užlūžti"
• kai studentų sąrašo generavimas bei rūšiavimas į dvi grupes įvyks, tai jums praneš "Įvykdyta!" ir galėsite uždaryti programą
• Jeigu norėsite tęsti generuoti jūsų norimo studentų skaičiaus failus toliau, tada įvesite "N" ir spausite Enter.

# 1.0v
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
| 10 000 000          | 53.1483                                       | -                                                                 |

  # 0.4v
  Sugeneruojami sąrašai iš 1000, 10 000, 100 000, 1 000 000 ir 10 000 000 studentų bei pažymių, vėliau apskaičiuojamas vidurkis su mediana ir rezultatai išvedami į du atskirus failus: nuskriausti.txt (kai vidurkis < 5) ir kietiakai.txt (kai vidurkis > 5). Studentai surūšiuoti pagal rezultatus.

SPARTOS ANALIZĖ:
su 1000 studentų
Failo su studentais kurimas uztruko: 0.0460003 s
Failo su studentais nuskaitymas uztruko: 0.0416295
Failo isvedimas su studentais i kietiakus uztruko : 0.0304543 s
Failo isvedimas su studentais i nuskriaustus uztruko : 0.0207351 s
Failo rusiavimas i dvi grupes uztruko : 0.0921282 s

su 10 000 studentų
Failo su studentais kurimas uztruko: 0.458249 s
Failo su studentais nuskaitymas uztruko: 0.401954
Failo isvedimas su studentais i kietiakus uztruko : 0.208214 s
Failo isvedimas su studentais i nuskriaustus uztruko : 0.165227 s
Failo rusiavimas i dvi grupes uztruko : 0.645861 s

su 100 000 studentų
Failo su studentais kurimas uztruko: 4.29371 s
Failo su studentais nuskaitymas uztruko: 4.19198
Failo isvedimas su studentais i kietiakus uztruko : 2.07282 s
Failo isvedimas su studentais i nuskriaustus uztruko : 1.44359 s
Failo rusiavimas i dvi grupes uztruko : 6.40551 s

su 1 000 000 studentų
Failo su studentais kurimas uztruko: 43.1077 s
Failo su studentais nuskaitymas uztruko: 43.1539
Failo isvedimas su studentais i kietiakus uztruko : 23.0356 s
Failo isvedimas su studentais i nuskriaustus uztruko : 16.0895 s
Failo rusiavimas i dvi grupes uztruko : 66.7805 s
  
# 0.3v
Leidžiama naudotojui pasirinkti, ar įvesti studento duomenis bei pažymius ranka, ar įkelti iš failo. Jeigu duomenis veda naudotojas, jis turi galimybę pasirinkti, ar įvesti pažymius pačiam, ar sugeneruoti automatiškai. Papildyta Try-catch funkcija bei sukurti headers'ai.
  
# 0.2v
Duodame programai nuskaityti txt failą su studentų pažymiais, suskaičiuojame medianą bei vidurkį ir išsaugojame naujame txt faile rezultatus: Vardas, Pavardė, vidurkis, mediana.
  
# 0.1v
Pradedame su funkcijomis, kurios atsitiktinai sugeneruoja pažymius ir automatiškai įrašo juos į rezultatus ir skaičiuoja vidurkį. Toliau duodame pasirinkimą įvesti pažymius rankinių būdu bei gauname studento informaciją: vardą, pavardę. Tada suskaičiuojame medianą ir išvedame visą informaciją.
