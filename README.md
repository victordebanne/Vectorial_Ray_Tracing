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

$$\text{le coté} \quad i_C + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|}\quad \text{et le coté} \quad j_C + \frac{j_{\vec{AB}}}{|j_{\vec{AB}}|}$$

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
coin_1 \quad = \begin{pmatrix}i_C + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|} \quad & j_C \end{pmatrix} \quad \text{et} \quad 
coin_2 \quad = \begin{pmatrix}i_C + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|} \quad & j_C + \frac{j_{\vec{AB}}}{|j_{\vec{AB}}|} \end{pmatrix}
$$

On exprime donc alors les deux vecteurs depuis le point de départ

$$\vec{A coin_1} = 
\begin{pmatrix}  
i_C + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|} - A_i\\ 
j_C - A_j
\end{pmatrix}
\quad \text{et} \quad
\vec{A coin_2} = 
\begin{pmatrix}  
i_C + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|} - A_i \\ 
j_C + \frac{j_{\vec{AB}}}{|j_{\vec{AB}}|} - A_j
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
j_C + \frac{j_{\vec{AB}}}{|j_{\vec{AB}}|}
\end{pmatrix} \\
&\text{si} \quad \det(M) \cdot \det(N) < 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|}\\
j_C  
\end{pmatrix} \\
&\text{si} \quad \det(M) \cdot \det(N) = 0 \quad : \quad \\
&\text{ } \quad \det(M) = 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|}\\
j_C  
\end{pmatrix} \\
&\text{ } \quad \det(N) = 0 \quad : \quad 
C \leftarrow 
\begin{pmatrix}
i_C  + \frac{i_{\vec{AB}}}{|i_{\vec{AB}}|}\\
j_C  + \frac{j_{\vec{AB}}}{|j_{\vec{AB}}|}
\end{pmatrix} \\
\end{align}
$$

# Analyse de la complexité







