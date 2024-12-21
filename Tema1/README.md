Servere:
Pentru prima problema, primul lucru pe care l-am observat au fost limitele
intre care voi lucra: curentul dorit va fi evident intre curentul minim
pe care in intalnesc in vectorul C si cel maxim, iar rezultatul adica
maximul puterii cele mai mici nu poate depasi minimul din vectorul P.
Am vazut ca rezultatul pentru tot ansamblul de
servere se comporta la fel ca rezultatul pentru un singur server: creste pana
la un punct optim (unde avem valoarea cautata) dupa care scade.
Am reusit sa combin cautarea binara cu ideea mea de a vedea trendul
in care merge functia si am reusit sa gasesc si optimul.
Complexitatea finala este: logaritm2(n) pentru injumatatirea intervalului,
insa din cauza functiei de calcul a puterii liniara ar fi n * logaritm2(n),
+ cateva apeluri O(n) pentru initializarea rezultatului, pentru cazul cu 1
server de exemplu si un for cu 1-2-3 apeluri ca sa fiu sigura ca rezultatul
va fi mereu corect.

Colorare:
Aceasta problema a impus cele mai multe dificultati la gasirea formulei
care generalizeaza colorarea imaginii. O data ce am gasit-o, optimizarea
am facut-o modificand functia pow de care mi-am adus aminte de la laborator.
Formula poate fi descrisa astfel:
    H
    - 6 moduri, prima aparitie
    - result * 3 moduri, H + H
    - result * 2moduri, V + H
    V
    - 3 moduri, prima aparitie
    - result * 1 moduri , H + V
    - result * 2 moduri , V + V
Complexitatea algoritmului este O(N * logN).

Compresie:
Pentru a rezolva problema 3, m-am gandit sa parcurg ambii vectori simultan:
cat timp nu am ajuns la final, vad daca elementele curente sunt egale;
daca da - trec la compararea urmatoarelor, daca nu - efectuez sume pana le 
egalez. La final, verific daca au mai ramas elemente in vector pentru a-mi
da seama daca se poate aplica in mod corect compresia.
Complexitatea algoritmului este O(n + m), unde n și m sunt dimensiunile
celor doi vectori.

Criptat:
Pentru citire, am decis sa fac o functie separata pentru a-mi putea
"incarca" datele in structura de date (cuvinte) cu care lucrez.
Pentru fiecare litera din alfabet, sortez cuvintele in ordinea 
descrescatoare a procentului acelei litere in cuvinte si, dacă procentele
sunt egale, sortez descrescator după lungimea cuvintelor.
In password, incerc sa formez cea mai lunga parola posibila folosind cuvintele
sortate, asigurand-ma ca litera pe care ma concentrez devine litera dominanta 
in constructia parolei.
Complexitatea algoritmului este O(n * m * logn), unde n este numărul de cuvinte
si m este lungimea maximă a unui cuvant.

Oferta:
Aici am optat pentru programare dinamica. Iterez prin produsele citite astfel:
-daca sunt la primul produs, acela este singurul, deci cel mai mic pret de pana acum;
-daca sunt la al doilea, se poate face un grup de 2 deci fac minimul preturilor
produselor grupate ori luate cate doua;
-mai departe, se pot lua si in grup de cate 3, deci verific minimul intre toate cele 3 
posibilitati de grupare. 
Complexitatea algoritmului este O(N * logN), unde N reprezintă numărul
de produse.