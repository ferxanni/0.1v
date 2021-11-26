# 0.5v
vector<data> pakeistas į list<vector> ir išmatuota failo nuskaitymo trukmė bei rūšiavimo, išvedimo į du atskirus failus(kietiakai.txt ir nuskriausti.txt) trukmė.

kompiuterio parametrai: 
AMD Ryzen 5 3500U with Radeon Vega Mobile Gfx     2.10 GHz
8 GB RAM
512 GB SSD

SPARTOS ANALIZĖ:
std::list
| Studentų skaičius | Failo su studentais nuskaitymas | Failo rūšiavimas ir išvedimas į dvi grupes |
|--------------------|------------------------------------|----------------------------------------------|
| 1 000                   | 0.0053995 s                                 | 0.0138256 s                    |
| 10 000                 | 0.0502726 s                                 | 0.155001 s                      |
| 100 000               | 0.516876 s                                   | 1.50728 s                      |
| 1 000 000            | 5.98676 s                                     | 14.1559 s                      |
| 10 000 000          | 53.1483                                       | -                               |

  
palyginimui std::vector (paimta iš 0.3v spartos analizės)
| Studentų skaičius | Failo su studentais nuskaitymas | Failo rūšiavimas ir išvedimas į dvi grupes |
|--------------------|------------------------------------|----------------------------------------------|
| 1 000                   | 0.0416295                                  | 0.0921282                    |
| 10 000                 | 0.401954                                    | 0.645861                     |
| 100 000               | 4.19198                                      | 6.40551                      |
| 1 000 000            | 43.1539                                       | 66.7805                      |

