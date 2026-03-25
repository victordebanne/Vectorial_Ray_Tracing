# Vectorial_Ray_Tracing

l'algorithme de raytracing $2D$ que je propose repose sur le produit vectoriel. 
Cet algorithme fonctionne purement avec la manipulation des entiers. Il ne s'agit ni de l'algorithme de *Bresenham* qui est une approximationn, ni de delui de *Amantides and Woo* dont je parlerai plus bas, et avec lesquels je comparerai les approches et les compléxités. 

Mon objectif, ici, était de marquer sur une grille en deux dimensions les cases traversées par une ligne reliant deux cases de la grille. 

Soient $A$ et $B$, deux cases d'une grille $I \times J$. avec 

$$A = \begin{pmatrix} i_A & j_A \end{pmatrix} \text{et} \quad B = \begin{pmatrix} i_B & j_B \end{pmatrix}$$

on note le vecteur 

$$\vec{AB} \quad \text{tel que} \quad \vec{AB} = 
\begin{pmatrix} 
i_{\vec{AB}} = i_B - i_A \\
j_{\vec{AB}} = j_B - j_A 
\end{pmatrix}
$$

# Fonctionnement de l'algorithme

l'algorithme que je propose repose sur l'identification du coté de la case courante traversée par le segment $AB$. je note la case courante avec 

$$C = \begin{pmatrix} i_C & j_C \end{pmatrix}$$

en deux dimensions, seuls deux cotés peuvent être traversés. 

on exprime $\vec{di}$ et $\vec{dj}$ comme : 

$$
\begin{align}
di &= 
\begin{cases}
di \\
0 \quad \text{sinon}
\end{cases} \\
\text{et} \\
dj &= 
\begin{cases}
dj \\
0 \quad \text{sinon}
\end{cases} \\
\end{align}
$$

$$\text{le coté} \quad i_C + di\quad \text{et le coté} \quad j_C + dj$$

il suffit alors d'identifier lequel des deux est traversé par le segment. On utilise le produit vectoriel $2D$ comme le determinant de la matrice

$$
\begin{pmatrix} 
u_i & v_i \\
u_j & v_j
\end{pmatrix}
$$

c'est à dire l'air signé entre les deux vecteurs $\vec{u}$ et $\vec{v}$. 

on regarde donc deux coins de la case courante, correctement choisis pour être deux coins d'un coté possible de passage. 

$$
coin_1 \quad = \begin{pmatrix}i_C + di \quad & j_C \end{pmatrix} \quad \text{et} \quad 
coin_2 \quad = \begin{pmatrix}i_C + di \quad & j_C + dj \end{pmatrix}
$$

On exprime donc alors les deux vecteurs depuis le point de départ

$$\vec{A coin_1} = 
\begin{pmatrix}  
i_C + di - A_i\\ 
j_C - A_j
\end{pmatrix}
\quad \text{et} \quad
\vec{A coin_2} = 
\begin{pmatrix}  
i_C + di - A_i \\ 
j_C + dj - A_j
\end{pmatrix}
$$

on calcule donc l'aire formée par le vecteur $\vec{AB}$ et chacun des vecteurs $\vec{A coin_1}$ et $\vec{A coin_2}$ à l'aide du produit vectoriel $2D$ ou du determinant de la matrice : 

$$
\begin{align}
&M = 
\begin{pmatrix} 
Acoin_{1i} & AB_{i} \\
Acoin_{1j} & AB_{j}
\end{pmatrix}
\quad \text{et} \quad
N = 
\begin{pmatrix} 
Acoin_{2i} & AB_{i} \\
Acoin_{2j} & AB_{j}
\end{pmatrix} \\
&\det(M) = Acoin_{1i} \cdot AB_{j} - Acoin_{1j} \cdot AB_{i}\\
\quad \text{et} \quad \\
&\det(N) = Acoin_{2i} \cdot AB_{j} - Acoin_{2j} \cdot AB_{i} \\
&\text{si} \quad \det(M) \cdot \det(N) > 0 \quad : \quad \text{le segment traverse l'autre coté} \\
&\text{si} \quad \det(M) \cdot \det(N) < 0 \quad : \quad \text{le segment traverse le coté observé} \\
&\text{si} \quad \det(M) \cdot \det(N) = 0 \quad : \quad \text{le segment passe par un des coins} \\
&\text{on identifie le coin traversé en regardant quel determinant est égal à 0}
\end{align}
$$

# Mise à jour de la case courante 

$$
\begin{align}
&\text{si} \quad \det(M) \cdot \det(N) > 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  \\
j_C + dj
\end{pmatrix} \\
&\text{si} \quad \det(M) \cdot \det(N) < 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  + di\\
j_C  
\end{pmatrix} \\
&\text{si} \quad \det(M) \cdot \det(N) = 0 \quad : \quad \\
&\text{ } \quad \det(M) = 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  + di\\
j_C  
\end{pmatrix} \\
&\text{ } \quad \det(N) = 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  + di\\
j_C  + dj
\end{pmatrix} \\
\end{align}
$$


# Cas limite $\det(M) \cdot \det(N) = 0$

$$
\begin{align}
B &= 
\begin{pmatrix}
A_i + n\ di \\
A_j + m\ dj \\
\end{pmatrix}\\
&\text{si} \quad B_i = A_i \quad \text{alors} \quad n = 0 \quad \text{ou} \quad di = 0\\
&\text{si} \quad B_j = A_j \quad \text{alors} \quad m = 0 \quad \text{ou} \quad dj = 0\\
\end{align}
$$

Donc $dj = 0$ est l'unique cas où $\vec{AB}$ colinéaire à $\vec{Acoin_1}$ 

C'est pour quoi il est correct de traiter le cas limite ainsi : 

```c
comp = detA * detB;
if(comp > 0){
    C.j += dj;
}
else if(comp < 0){
    C.i += di;
}
else if(comp == 0){
    C.i += di;
    C.j += dj;
}
```

# Analyse de la complexité

on peut stocker dans des variables au début de l'algorithme 

$$
\begin{align}
&di \quad \text{et} \quad dj \quad \text{: deux divisions, mais peut être remplacé par une analyse du premier bit de l'entier signé} \\
&\text{calcul de} \ \vec{AB} \quad \text{:   deux soustractions} \\
\end{align}
$$

à chaque étape de l'algorithme, on fait : 

$$
\begin{align}
&2 \cdot + \quad \text{une par coin}\\
&4 \cdot - \text{une par coin et une par determinant}\\
&2 \cdot \times \text{une par determinant}\\
&1 - 2 \quad \text{comparaisons de bits, une pour le cas régulier, deux pour le determinant égal à 0}
\end{align}
$$

pour $n$ cases traversées, la complexité est de : 

$$
\begin{align}
&c_0 = 4 \quad \text{deux soustractions et deux comparaisons}\\
&c_1 = 4 + 2 + 2 = 8 \text{quatre additions, deux multiplications et deux comparaisons}\\
&\text{donc} \quad T_{total} = c_0 + c_1 \cdot n = 4 + 8n\\
&\text{avec pour complexité} \quad \mathcal{O}(n)
\end{align}
$$





