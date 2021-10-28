# 0.1v
Pradedame su funkcijomis, kurios atsitiktinai sugeneruoja pažymius ir automatiškai įrašo juos į rezultatus ir skaičiuoja vidurkį. Toliau duodame pasirinkimą įvesti pažymius rankinių būdu bei gauname studento informaciją: vardą, pavardę. Tada suskaičiuojame medianą ir išvedame visą informaciją.

# 0.2v
Duodame programai nuskaityti txt failą su studendų pažymiais, suskaičiuojame medianą bei vidurkį ir išsaugojame naujame txt faile rezultatus: Vardas, Pavardė, vidurkis, mediana.

# 0.3v
Leidžiama naudotojui pasirinkti, ar įvesti studento duomenis bei pažymius ranka, ar įkelti iš failo. Jeigu duomenis veda naudotojas, jis turi galimybę pasirinkti, ar įvesti pažymius pačiam, ar sugeneruoti automatiškai. Papildyta Try-catch funkcija bei sukurti headers'ai.

# 0.4v
Sugeneruojami sąrašai iš 1000, 10 000, 100 000, 1 000 000 ir 10 000 000 studentų bei pažymių, vėliau apskaičiuojamas vidurkis su mediana ir rezultatai išvedami į du atskirus failus: protingi.txt (kai vidurkis < 5) ir protingesni.txt (kai vidurkis > 5). Studentai surušiuoti pagal rezultatus.

# Spartos analizė:
su 1000 studentų:
Failo su studentais kurimas uztruko: 0.0460003 s.
Failo su studentais nuskaitymas uztruko: 0.0416295 s.
Failo isvedimas su  studentais i kietiakus uztruko : 0.0304543 s.
Failo isvedimas su studentais i nuskriaustus uztruko : 0.0207351 s.
Failo rusiavimas i dvi grupes uztruko : 0.0921282 s.

su 10 000 studentų:
Failo su studentais kurimas uztruko: 0.458249 s.
Failo su studentais nuskaitymas uztruko: 0.401954 s.
Failo isvedimas su  studentais i kietiakus uztruko : 0.208214 s.
Failo isvedimas su studentais i nuskriaustus uztruko : 0.165227 s.
Failo rusiavimas i dvi grupes uztruko : 0.645861 s.

su 100 000 studentų
Failo su studentais kurimas uztruko: 4.29371 s
Failo su studentais nuskaitymas uztruko: 4.19198
Failo isvedimas su  studentais i kietiakus uztruko : 2.07282 s
Failo isvedimas su studentais i nuskriaustus uztruko : 1.44359 s
Failo rusiavimas i dvi grupes uztruko : 6.40551 s

su 1 000 000 studentų:
Failo su studentais kurimas uztruko: 43.1077 s.
Failo su studentais nuskaitymas uztruko: 43.1539 s.
Failo isvedimas su  studentais i kietiakus uztruko : 23.0356 s.
Failo isvedimas su studentais i nuskriaustus uztruko : 16.0895 s.
Failo rusiavimas i dvi grupes uztruko : 66.7805 s.
