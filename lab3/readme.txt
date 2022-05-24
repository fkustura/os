U ovu tekstualnu datoteku spremio sam ispis u kojem je vidljivo ponašanje programa u situacijama koje se spominju u zadatku.
Globalnu varijablu postavljeni_broj_dretvi inicijalizirao sam na broj 5.
Redefiniranje broja radnih dretvi učinio sam u terminalu, tijekom obrade brojeva 194, 198, 207, 221 i 233.
Broj radnih dretvi mijenjao se ovako: 5 (inicijalno) -> 1 -> 2 -> 3 -> 9 -> 3
Tijekom ovog testiranja nisam koristio Makefile, ali naknadno sam i to napravio.

filip@DESKTOP-LLNMFL4:/mnt/c/Users/Filip/Desktop/os/lab3$ gcc lab3.c datoteke.c -lpthread -lm -o prog
filip@DESKTOP-LLNMFL4:/mnt/c/Users/Filip/Desktop/os/lab3$ ./prog status.txt obrada.txt

Dretva 1 krece s radom (broj=149):
Dretva 1 upravo kvadrira broj 149...
Dretva 1 je kvadrirala broj 149; staje s radom.

Dretva 3 krece s radom (broj=150):
Dretva 3 upravo kvadrira broj 150...
Dretva 3 je kvadrirala broj 150; staje s radom.

Dretva 1 krece s radom (broj=151):
Dretva 1 upravo kvadrira broj 151...
Dretva 1 je kvadrirala broj 151; staje s radom.

Dretva 4 krece s radom (broj=152):
Dretva 4 upravo kvadrira broj 152...
Dretva 4 je kvadrirala broj 152; staje s radom.

Dretva 1 krece s radom (broj=153):
Dretva 1 upravo kvadrira broj 153...
Dretva 1 je kvadrirala broj 153; staje s radom.

Dretva 2 krece s radom (broj=154):
Dretva 2 upravo kvadrira broj 154...
Dretva 2 je kvadrirala broj 154; staje s radom.

Dretva 1 krece s radom (broj=155):
Dretva 1 upravo kvadrira broj 155...
Dretva 1 je kvadrirala broj 155; staje s radom.

Dretva 3 krece s radom (broj=156):
Dretva 3 upravo kvadrira broj 156...
Dretva 3 je kvadrirala broj 156; staje s radom.

Dretva 1 krece s radom (broj=157):
Dretva 1 upravo kvadrira broj 157...
Dretva 1 je kvadrirala broj 157; staje s radom.

Dretva 2 krece s radom (broj=158):
Dretva 2 upravo kvadrira broj 158...
Dretva 2 je kvadrirala broj 158; staje s radom.

Dretva 1 krece s radom (broj=159):
Dretva 1 upravo kvadrira broj 159...
Dretva 1 je kvadrirala broj 159; staje s radom.

Dretva 2 krece s radom (broj=160):
Dretva 2 upravo kvadrira broj 160...
Dretva 2 je kvadrirala broj 160; staje s radom.

Dretva 1 krece s radom (broj=161):
Dretva 1 upravo kvadrira broj 161...
Dretva 1 je kvadrirala broj 161; staje s radom.

Dretva 2 krece s radom (broj=162):
Dretva 2 upravo kvadrira broj 162...
Dretva 2 je kvadrirala broj 162; staje s radom.

Dretva 1 krece s radom (broj=163):
Dretva 1 upravo kvadrira broj 163...
Dretva 1 je kvadrirala broj 163; staje s radom.

Dretva 2 krece s radom (broj=164):
Dretva 2 upravo kvadrira broj 164...
Dretva 2 je kvadrirala broj 164; staje s radom.

Dretva 5 krece s radom (broj=165):
Dretva 5 upravo kvadrira broj 165...
Dretva 5 je kvadrirala broj 165; staje s radom.

Dretva 2 krece s radom (broj=166):
Dretva 2 upravo kvadrira broj 166...
Dretva 2 je kvadrirala broj 166; staje s radom.

Dretva 1 krece s radom (broj=167):
Dretva 1 upravo kvadrira broj 167...
Dretva 1 je kvadrirala broj 167; staje s radom.

Dretva 4 krece s radom (broj=168):
Dretva 4 upravo kvadrira broj 168...
Dretva 4 je kvadrirala broj 168; staje s radom.

Dretva 1 krece s radom (broj=169):
Dretva 1 upravo kvadrira broj 169...
Dretva 1 je kvadrirala broj 169; staje s radom.

Dretva 2 krece s radom (broj=170):
Dretva 2 upravo kvadrira broj 170...
Dretva 2 je kvadrirala broj 170; staje s radom.

Dretva 3 krece s radom (broj=171):
Dretva 3 upravo kvadrira broj 171...
Dretva 3 je kvadrirala broj 171; staje s radom.

Dretva 2 krece s radom (broj=172):
Dretva 2 upravo kvadrira broj 172...
Dretva 2 je kvadrirala broj 172; staje s radom.

Dretva 1 krece s radom (broj=173):
Dretva 1 upravo kvadrira broj 173...
Dretva 1 je kvadrirala broj 173; staje s radom.

Dretva 2 krece s radom (broj=174):
Dretva 2 upravo kvadrira broj 174...
Dretva 2 je kvadrirala broj 174; staje s radom.

Dretva 5 krece s radom (broj=175):
Dretva 5 upravo kvadrira broj 175...
Dretva 5 je kvadrirala broj 175; staje s radom.

Dretva 2 krece s radom (broj=176):
Dretva 2 upravo kvadrira broj 176...
Dretva 2 je kvadrirala broj 176; staje s radom.

Dretva 1 krece s radom (broj=177):
Dretva 1 upravo kvadrira broj 177...
Dretva 1 je kvadrirala broj 177; staje s radom.

Dretva 2 krece s radom (broj=178):
Dretva 2 upravo kvadrira broj 178...
Dretva 2 je kvadrirala broj 178; staje s radom.

Dretva 1 krece s radom (broj=179):
Dretva 1 upravo kvadrira broj 179...
Dretva 1 je kvadrirala broj 179; staje s radom.

Dretva 3 krece s radom (broj=180):
Dretva 3 upravo kvadrira broj 180...
Dretva 3 je kvadrirala broj 180; staje s radom.

Dretva 1 krece s radom (broj=181):
Dretva 1 upravo kvadrira broj 181...
Dretva 1 je kvadrirala broj 181; staje s radom.

Dretva 2 krece s radom (broj=182):
Dretva 2 upravo kvadrira broj 182...
Dretva 2 je kvadrirala broj 182; staje s radom.

Dretva 1 krece s radom (broj=183):
Dretva 1 upravo kvadrira broj 183...
Dretva 1 je kvadrirala broj 183; staje s radom.

Dretva 2 krece s radom (broj=184):
Dretva 2 upravo kvadrira broj 184...
Dretva 2 je kvadrirala broj 184; staje s radom.

Dretva 5 krece s radom (broj=185):
Dretva 5 upravo kvadrira broj 185...
Dretva 5 je kvadrirala broj 185; staje s radom.

Dretva 2 krece s radom (broj=186):
Dretva 2 upravo kvadrira broj 186...
Dretva 2 je kvadrirala broj 186; staje s radom.

Dretva 1 krece s radom (broj=187):
Dretva 1 upravo kvadrira broj 187...
Dretva 1 je kvadrirala broj 187; staje s radom.

Dretva 4 krece s radom (broj=188):
Dretva 4 upravo kvadrira broj 188...
Dretva 4 je kvadrirala broj 188; staje s radom.

Dretva 1 krece s radom (broj=189):
Dretva 1 upravo kvadrira broj 189...
Dretva 1 je kvadrirala broj 189; staje s radom.

Dretva 2 krece s radom (broj=190):
Dretva 2 upravo kvadrira broj 190...
Dretva 2 je kvadrirala broj 190; staje s radom.

Dretva 1 krece s radom (broj=191):
Dretva 1 upravo kvadrira broj 191...
Dretva 1 je kvadrirala broj 191; staje s radom.

Dretva 2 krece s radom (broj=192):
Dretva 2 upravo kvadrira broj 192...
Dretva 2 je kvadrirala broj 192; staje s radom.

Dretva 1 krece s radom (broj=193):
Dretva 1 upravo kvadrira broj 193...
Dretva 1 je kvadrirala broj 193; staje s radom.

Dretva 2 krece s radom (broj=194):
Dretva 2 upravo kvadrira broj 194...
1
Dretva 2 je kvadrirala broj 194; staje s radom.

Dretva 1 krece s radom (broj=195):
Dretva 1 upravo kvadrira broj 195...
Dretva 1 je kvadrirala broj 195; staje s radom.

Dretva 1 krece s radom (broj=196):
Dretva 1 upravo kvadrira broj 196...
Dretva 1 je kvadrirala broj 196; staje s radom.

Dretva 1 krece s radom (broj=197):
Dretva 1 upravo kvadrira broj 197...
Dretva 1 je kvadrirala broj 197; staje s radom.

Dretva 1 krece s radom (broj=198):
Dretva 1 upravo kvadrira broj 198...
2
Dretva 1 je kvadrirala broj 198; staje s radom.

Dretva 1 krece s radom (broj=199):
Dretva 1 upravo kvadrira broj 199...
Dretva 1 je kvadrirala broj 199; staje s radom.

Dretva 5 krece s radom (broj=200):
Dretva 5 upravo kvadrira broj 200...
Dretva 5 je kvadrirala broj 200; staje s radom.

Dretva 1 krece s radom (broj=201):
Dretva 1 upravo kvadrira broj 201...
Dretva 1 je kvadrirala broj 201; staje s radom.

Dretva 1 krece s radom (broj=202):
Dretva 1 upravo kvadrira broj 202...
Dretva 1 je kvadrirala broj 202; staje s radom.

Dretva 1 krece s radom (broj=203):
Dretva 1 upravo kvadrira broj 203...
Dretva 1 je kvadrirala broj 203; staje s radom.

Dretva 1 krece s radom (broj=204):
Dretva 1 upravo kvadrira broj 204...
Dretva 1 je kvadrirala broj 204; staje s radom.

Dretva 5 krece s radom (broj=205):
Dretva 5 upravo kvadrira broj 205...
Dretva 5 je kvadrirala broj 205; staje s radom.

Dretva 1 krece s radom (broj=206):
Dretva 1 upravo kvadrira broj 206...
Dretva 1 je kvadrirala broj 206; staje s radom.

Dretva 1 krece s radom (broj=207):
Dretva 1 upravo kvadrira broj 207...
3
Dretva 1 je kvadrirala broj 207; staje s radom.

Dretva 2 krece s radom (broj=208):
Dretva 2 upravo kvadrira broj 208...
Dretva 2 je kvadrirala broj 208; staje s radom.

Dretva 1 krece s radom (broj=209):
Dretva 1 upravo kvadrira broj 209...
Dretva 1 je kvadrirala broj 209; staje s radom.

Dretva 2 krece s radom (broj=210):
Dretva 2 upravo kvadrira broj 210...
Dretva 2 je kvadrirala broj 210; staje s radom.

Dretva 1 krece s radom (broj=211):
Dretva 1 upravo kvadrira broj 211...
Dretva 1 je kvadrirala broj 211; staje s radom.

Dretva 2 krece s radom (broj=212):
Dretva 2 upravo kvadrira broj 212...
Dretva 2 je kvadrirala broj 212; staje s radom.

Dretva 1 krece s radom (broj=213):
Dretva 1 upravo kvadrira broj 213...
Dretva 1 je kvadrirala broj 213; staje s radom.

Dretva 2 krece s radom (broj=214):
Dretva 2 upravo kvadrira broj 214...
Dretva 2 je kvadrirala broj 214; staje s radom.

Dretva 1 krece s radom (broj=215):
Dretva 1 upravo kvadrira broj 215...
Dretva 1 je kvadrirala broj 215; staje s radom.

Dretva 2 krece s radom (broj=216):
Dretva 2 upravo kvadrira broj 216...
Dretva 2 je kvadrirala broj 216; staje s radom.

Dretva 1 krece s radom (broj=217):
Dretva 1 upravo kvadrira broj 217...
Dretva 1 je kvadrirala broj 217; staje s radom.

Dretva 2 krece s radom (broj=218):
Dretva 2 upravo kvadrira broj 218...
Dretva 2 je kvadrirala broj 218; staje s radom.

Dretva 1 krece s radom (broj=219):
Dretva 1 upravo kvadrira broj 219...
Dretva 1 je kvadrirala broj 219; staje s radom.

Dretva 5 krece s radom (broj=220):
Dretva 5 upravo kvadrira broj 220...
Dretva 5 je kvadrirala broj 220; staje s radom.

Dretva 1 krece s radom (broj=221):
Dretva 1 upravo kvadrira broj 221...
9
Dretva 1 je kvadrirala broj 221; staje s radom.

Dretva 2 krece s radom (broj=222):
Dretva 2 upravo kvadrira broj 222...
Dretva 2 je kvadrirala broj 222; staje s radom.

Dretva 1 krece s radom (broj=223):
Dretva 1 upravo kvadrira broj 223...
Dretva 1 je kvadrirala broj 223; staje s radom.

Dretva 8 krece s radom (broj=224):
Dretva 8 upravo kvadrira broj 224...
Dretva 8 je kvadrirala broj 224; staje s radom.

Dretva 9 krece s radom (broj=225):
Dretva 9 upravo kvadrira broj 225...
Dretva 9 je kvadrirala broj 225; staje s radom.

Dretva 2 krece s radom (broj=226):
Dretva 2 upravo kvadrira broj 226...
Dretva 2 je kvadrirala broj 226; staje s radom.

Dretva 1 krece s radom (broj=227):
Dretva 1 upravo kvadrira broj 227...
Dretva 1 je kvadrirala broj 227; staje s radom.

Dretva 3 krece s radom (broj=228):
Dretva 3 upravo kvadrira broj 228...
Dretva 3 je kvadrirala broj 228; staje s radom.

Dretva 1 krece s radom (broj=229):
Dretva 1 upravo kvadrira broj 229...
Dretva 1 je kvadrirala broj 229; staje s radom.

Dretva 2 krece s radom (broj=230):
Dretva 2 upravo kvadrira broj 230...
Dretva 2 je kvadrirala broj 230; staje s radom.

Dretva 7 krece s radom (broj=231):
Dretva 7 upravo kvadrira broj 231...
Dretva 7 je kvadrirala broj 231; staje s radom.

Dretva 8 krece s radom (broj=232):
Dretva 8 upravo kvadrira broj 232...
Dretva 8 je kvadrirala broj 232; staje s radom.

Dretva 1 krece s radom (broj=233):
Dretva 1 upravo kvadrira broj 233...
3
Dretva 1 je kvadrirala broj 233; staje s radom.

Dretva 1 krece s radom (broj=234):
Dretva 1 upravo kvadrira broj 234...
Dretva 1 je kvadrirala broj 234; staje s radom.

Dretva 1 krece s radom (broj=235):
Dretva 1 upravo kvadrira broj 235...
Dretva 1 je kvadrirala broj 235; staje s radom.

Dretva 1 krece s radom (broj=236):
Dretva 1 upravo kvadrira broj 236...
Dretva 1 je kvadrirala broj 236; staje s radom.

Dretva 1 krece s radom (broj=237):
Dretva 1 upravo kvadrira broj 237...
Dretva 1 je kvadrirala broj 237; staje s radom.

Dretva 7 krece s radom (broj=238):
Dretva 7 upravo kvadrira broj 238...
Dretva 7 je kvadrirala broj 238; staje s radom.

Dretva 1 krece s radom (broj=239):
Dretva 1 upravo kvadrira broj 239...
Dretva 1 je kvadrirala broj 239; staje s radom.

Dretva 8 krece s radom (broj=240):
Dretva 8 upravo kvadrira broj 240...
Dretva 8 je kvadrirala broj 240; staje s radom.

Dretva 1 krece s radom (broj=241):
Dretva 1 upravo kvadrira broj 241...
Dretva 1 je kvadrirala broj 241; staje s radom.

Dretva 1 krece s radom (broj=242):
Dretva 1 upravo kvadrira broj 242...
Dretva 1 je kvadrirala broj 242; staje s radom.

Dretva 1 krece s radom (broj=243):
Dretva 1 upravo kvadrira broj 243...
Dretva 1 je kvadrirala broj 243; staje s radom.

Dretva 1 krece s radom (broj=244):
Dretva 1 upravo kvadrira broj 244...
Dretva 1 je kvadrirala broj 244; staje s radom.

Dretva 7 krece s radom (broj=245):
Dretva 7 upravo kvadrira broj 245...
Dretva 7 je kvadrirala broj 245; staje s radom.

Dretva 1 krece s radom (broj=246):
Dretva 1 upravo kvadrira broj 246...
Dretva 1 je kvadrirala broj 246; staje s radom.
^C
filip@DESKTOP-LLNMFL4:/mnt/c/Users/Filip/Desktop/os/lab3$