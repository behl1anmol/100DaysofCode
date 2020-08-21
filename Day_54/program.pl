studies(charlies, cse135).
studies(olivia, cse135).
studies(jack, cse131).
studies(arther, cse134).

teaches(kirke,cse135).
teaches(collin,cse131).
teaches(collin,cse171).
teaches(collin,cse134).

prof(X,Y) :- teaches(X,S), studies(Y,S).

sum:- read(A), read(B), C is (A+B), write(C).
area(R,A) :- A is ((22/7)*R*R).
area2:- read(R), A is ((22/7*R*R)), write(A).