Problema 1 - Numarare

Am ales sa-mi fac o functie de citire separata pentru grafuri pentru
a-mi fi mai usor sa parsez datele.
Mai departe, pentru a putea calcula numarul de lanturi elementare, 
am ales sa "ordonez"(noduri fara muchii interne/ noduri care depind 
de altele) primul graf, folosind sortarea topologica pe care am 
gasit-o in laborator. 
Apoi, parcurg graful sortat pornind de la primul nod si, daca gasesc
o muchie comuna cu cel de-al doilea graf, o adaug la rezultat cu
programare dinamica. 
Complexitate: O(N + M * log M) -> M * log M, unde N este numarul de 
noduri iar M numarul
de muchii.

Problema 2 - Trenuri

Aici am optat tot pentru sortarea topologica folosita la problema 1.
Această ordonare este esențială pentru calculul rezultatului pentru a 
se asigura că atunci când se calculează căile posibile către un oraș, 
toate căile potențiale de intrare au fost deja luate în considerare.
Asadar, iteram prin fiecare oras din graful sortat si verific vecinii.
Dacă călătoria de la A la B crește numărul de orașe distincte vizitate,
actualizez maximul folosind programare dinamica.
Complexitate: O(N + M), unde N este numarul de noduri iar M numarul
de muchii.

Problema 3 - Drumuri

La aceasta problema, m-am folosid de algoritmul Dijkstra, gasit in laborator.
M-am gandit sa gasesc distantele de la x la celelalte noduri, de la y la
celelalte noduri si de la toate nodurile la z (de aceea am avut nevoie
de graful transpus).
Iar pentru nodurile accesibile din toate direcțiile specificate, calculez
suma costurilor drumurilor minime respective astfel determin cea mai
mică valoare a sumei acestor drumuri pe parcursul întregului graf.
Complexitate: O( (N+M) logN ) pentru fiecare rulare a algoritmului
Dijkstra.