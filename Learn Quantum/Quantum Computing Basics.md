# Quantum Computing Basics

## Qubits

We define them as column vectors
```math
\vert 0 \rangle =\begin {pmatrix}1\\0\end{pmatrix} \textrm{  and  }\vert 1 \rangle =\begin {pmatrix}0\\1\end{pmatrix}
```
#### Superposition

It means that a quantum particle is in two states simultaneously. For example a photon of light being both horizontally and vertically polarized.
A qubit is in superposition if it is both
```math
\vert 0 \rangle \textrm{  and  } \vert 1 \rangle
``` at the same time.

Mathematically we can represent a qubit as a column vector of alpha and beta.
```math
\vert \psi \rangle =\begin {pmatrix}\alpha\\\beta\end{pmatrix}
```

The top element $\alpha$ indicates how much the qubit is in the $\vert 0 \rangle$  state and the bottom $\beta$ how much in $\vert 1 \rangle$ state.

If the qubit is in both 0 and 1 state, so it has non-0 numbers in the matrix, then we say it is in the superposition of 0 and 1, since it is in both of the states at the same time .

#### When we measure a quantum system, it collapses into he measured state.

If we have a photon that is in a superposition of both vertically and horizontally polarized, when we  measure it we can only measure it as horizontally or vertically polarized, and once it has been measured it will collapse into ( becomes ) the measured state. Meaning it will no longer be in a superposition state.

The same thing happens when we measure qubits.

When we measure a qubit we only measure a 0 or a 1. If we were to measure the qubit  $\vert \psi \rangle =\begin {pmatrix}\alpha\\\beta\end{pmatrix}$ we would not measure $\alpha$ or $\beta$, we would still only measure a 0 or a 1.

Those number of $\alpha$ and $\beta$ tell us the probability of measuring 0 or 1.

Probability of measuring $\vert \psi \rangle$ as 0 is: $\vert \alpha \vert$²
Probability of measuring $\vert \psi \rangle$ as 1 is: $\vert \beta \vert$²

The probabilities of $\alpha$ and $\beta$ must always add up to 1 so that we have a valid state of a qubit:
```math
\vert \alpha \vert² + \vert \beta \vert² = 1
```
#### Dirac Notation

We get a Dirac notation from the previous formula for the state of psi by splitting it into two vectors and factoring out alpha and beta. This makes it easier to manage multiple qubits.

```math
\vert \psi \rangle =\begin {pmatrix}\alpha\\\beta\end{pmatrix} =\begin {pmatrix}\alpha \\ 0 \end{pmatrix} + \begin {pmatrix} 0 \\ \beta \end{pmatrix} = \alpha \begin {pmatrix}\ 1 \\ 0 \end{pmatrix} + \beta \begin {pmatrix}\ 0 \\ 1 \end{pmatrix} = \alpha \vert 0 \rangle + \beta \vert 1 \rangle
```

Those brackets around 0, 1 and $\psi$ are called Ket Vectors and represent a quantum state.

### Bloch Sphere

We can represent a qubit $\vert \psi \rangle$ as a point on the surface of the Bloch Sphere.


On the top we  $\vert 0 \rangle$ state and on the bottom  $\vert 1 \rangle$. On the horizontal we have  $\vert + \rangle$ state,  $\vert - \rangle$ state,  $\vert i \rangle$ sate and  $\vert -i \rangle$ state.

The closer the qubit is to  $\vert 0 \rangle$ state or higher the qubit is in the sphere the higher the probability of measuring 0.

### Manipulating a Qubit - The X, Y and Z Gates

Just like the classical computer use logical gates to manipulate bits, quantum computer use gates to manipulate qubits.

##### X Gate
If we have a qubit in  $\vert 0 \rangle$ state and apply the X-gate we get a qubit in  $\vert 1 \rangle$ state.
The X-gate flips the qubit $\pi$ radians around the x-axis on the Bloch sphere.

##### Y Gate
It does the same thing  as the X-gate but it flips the qubit $\pi$ radians around the Y-axis on the Bloch sphere.

##### Z Gate
The Z-gate just like X and Y gates flips the qubit $\pi$ radians around the z-axis on the Bloch sphere.

Since the X, Y and Z gates rotate around the specified axis $\pi$ radians, if we apply the same gate twice we rotate around $2\pi$ radians, meaning the qubit will end up in the original position.

We can represent these three gates as matrices.
```math
X = \begin {pmatrix}0&&1\\1 && 0\end{pmatrix} \quad Y = \begin {pmatrix} 0 && -i\\ i && 0\end{pmatrix} \quad Z = \begin {pmatrix}1&&0\\0 && -1\end{pmatrix}
```
To apply the gate to the qubit we can mathematically multiply the matrix that represents the gate with the column vector of the qubit.
```math
X\vert\psi\rangle = \begin {pmatrix}0&&1\\1 && 0\end{pmatrix} \begin{pmatrix}\alpha\\\beta\end{pmatrix} = \begin {pmatrix}\beta\\\alpha\end{pmatrix}
```
Let $U=\begin {pmatrix}a&&b\\c && d\end{pmatrix}$ , be an arbitrary gate.

If we want to apply the arbitrary gate to the qubit we still look at the matrix but instead of using matrix multiplication we look at the columns of the matrix.

The first column of the matrix indicates the column vector the $\vert0\rangle$ state becomes after applying the gate. The same goes for the second column and the $\vert1\rangle$ state becomes. Then we can factor out both $\vert0\rangle$ and $\vert1\rangle$ states to get back into Dirac notation.
```math
\begin{align*}U\vert0\rangle= \begin {pmatrix}a\\c\end{pmatrix}= a\vert0\rangle + c\vert1\rangle \\ U\vert1\rangle= \begin {pmatrix}b\\d\end{pmatrix}= b\vert0\rangle + d\vert1\rangle \end{align*}
```
Also since quantum gates are linear if we apply an arbitrary gate U that gate acts on each of the superposition states individually.

```math
\begin{align*}Let \vert0\rangle = \alpha\vert0\rangle + \beta \vert1\rangle \\ U\vert\psi\rangle= U(\alpha\vert0\rangle + \beta\vert1\rangle) \\ U\vert\psi\rangle= \alpha U\vert0\rangle + \beta U \vert1\rangle \end{align*}
```

#### Introduction to Global Relative Phase

We can also rotate around the Z axis. That does not change the probability of a qubit but that is what makes quantum computing so powerful. We call it a phase.

We use complex numbers in exponential form in quantum computing since it gives us a nice mathematical way of rotating around a circle by changing the value of $\varphi$ .

By multiplying the $\vert 1 \rangle$ state by $e^{i\varphi}$ , we rotate around the z-axis (on the Bloch Sphere ) by $\varphi$ radians.
```math
\vert \psi \rangle = \alpha\vert0\rangle + e^{i\varphi}\beta\vert1\rangle
```
There are to types of phase Global and Relative Phase.

##### Global Phase
Global phase is when the entire qubit is multiplied by a complex number.
As it turns out global phase is physically irrelevant.

##### Relative Phase
Relative phase is when only the $\vert1\rangle$ state is multiplied by a complex number. Unlike global phase relative phase is extremely important and it matters in our calculations. It is when a $\vert1\rangle$state has a factor of a complex number and it rotates our qubit around the z-axis.

##### But what if we have different complex number both in a $\vert1\rangle$ and $\vert0\rangle$ state?

What we do is we factor out the complex number of a $\vert0\rangle$ state from the entire qubit, creating a global phase and a relative phase. And then we can discard the global phase leaving us with the qubit with only the relative phase.
```math
\begin{align*} e^{i\theta}\ \alpha\vert0\rangle\  + e^{i\varphi}\ \beta\ \vert1\rangle = \\   e^{i\theta}\ (\ \alpha\vert0\rangle + (e^{i\theta})^{-1}\ e^{i\varphi}\ \beta \ \vert1\rangle \ ) =\\   e^{i\theta}\ (\alpha\vert0\rangle + e^{i(\varphi-\theta)}\ \beta\ \vert1\rangle\ ) =\\  \alpha\vert0\rangle + e^{i(\varphi-\theta)}\ \beta\vert1\rangle  \end{align*}
```
The phase does not affect the probability of measuring a zero or a one as the qubit stays the same distance from $\vert0\rangle$ state and the $\vert1\rangle$ state.
We can prove this mathematically:
Probability of measuring
```math
1=\vert e^{i\varphi}\beta\vert0\rangle\vert ^2\Rightarrow 1=\vert e^{i\varphi} \vert^2\ \  \vert\beta\vert0\rangle\vert ^2
```
and we can remember that the magnitude of a complex number in exponential form $r e^{i\varphi}$ is $r$. And in the case of global phases $r=1$ .

#### Hadamard Gate

We can now define all the states on Bloch Sphere as such:

```math
\begin{align*}\vert+\rangle = \frac{1}{\sqrt{2}}\vert0\rangle + \frac{1}{\sqrt{2}}\vert1\rangle \\ \vert i\rangle = \frac{1}{\sqrt{2}}\vert0\rangle + \frac{i}{\sqrt{2}}\vert1\rangle \\ \vert-\rangle = \frac{1}{\sqrt{2}}\vert0\rangle - \frac{1}{\sqrt{2}}\vert1\rangle \\ \vert-i\rangle = \frac{1}{\sqrt{2}}\vert0\rangle - \frac{i}{\sqrt{2}}\vert1\rangle\end{align*}
```

Now we can look at the Hadamard Gate:

```math
H=\frac{1}{\sqrt{2}}\begin {bmatrix}1&&1\\1 && -1\end{bmatrix}
```

If we look at at how the gate acts on the qubit on the Bloch sphere we see that:

```math
\begin{align*}\vert0\rangle \xrightarrow{H} \vert+\rangle \quad \vert+\rangle \xrightarrow{H} \vert0\rangle \\ \vert1\rangle \xrightarrow{H} \vert-\rangle \quad \vert-\rangle \xrightarrow{H} \vert1\rangle   \end{align*}
```

This means that the Hadamard Gate is it's own inverse.

Applying the Hadamard to the arbitrary qubit sate in Dirac notations we can replace the $\vert0\rangle$ with $\vert+\rangle$ state, and the $\vert1\rangle$ with $\vert-\rangle$ state and expand.

```math
H (\alpha |0\rangle + e^{i\varphi} \beta |1\rangle)
```
```math
= \alpha H |0\rangle + e^{i\varphi} \beta H |1\rangle
```
```math
= \alpha |+\rangle + e^{i\varphi} \beta |-\rangle
```
```math
= \alpha \left( \frac{1}{\sqrt{2}} |0\rangle + \frac{1}{\sqrt{2}} |1\rangle \right) + e^{i\varphi} \beta \left( \frac{1}{\sqrt{2}} |0\rangle - \frac{1}{\sqrt{2}} |1\rangle \right)
```

```math
= \left( \frac{\alpha + e^{i\varphi} \beta}{\sqrt{2}} \right) |0\rangle
+ \left( \frac{\alpha - e^{i\varphi} \beta}{\sqrt{2}} \right) |1\rangle
```

It shows that states matter, as applying the Hadamard gate changes the probabilities of getting 0 or 1.

#### Phase Gates

Lets introduce two new gates the S and T gates and their conjugate transpose S "dagger" and T "dagger" which are their inverses.
```math
S =
\begin{pmatrix}
1 & 0 \\
0 & i
\end{pmatrix}
\quad
T =
\begin{pmatrix}
1 & 0 \\
0 & e^{i \frac{\pi}{4}}
\end{pmatrix}
```

```math
S^{\dagger} =
\begin{pmatrix}
1 & 0 \\
0 & -i
\end{pmatrix}
\quad
T^{\dagger} =
\begin{pmatrix}
1 & 0 \\
0 & e^{i \left(-\frac{\pi}{4}\right)}
\end{pmatrix}
```
Applying $S$ and then $S^{\dagger}$ we are back in the same position. Same goes for $T$ and $T^{\dagger}$.

The $S$ adds a relative phase of $e^{i\frac{\pi}{2}}$ and $T$ adds a relative phase of $e^{i\frac{\pi}{4}}$.
```math
\alpha\vert0\rangle +\beta\vert1\rangle \ \xrightarrow{S}\  \alpha\vert0\rangle +e^{i\frac{\pi}{2}}\beta\vert1\rangle
```
```math
\alpha\vert0\rangle +\beta\vert1\rangle \ \xrightarrow{T}\  \alpha\vert0\rangle +e^{i\frac{\pi}{4}}\beta\vert1\rangle
```

## Multiple Qubits

We can represent two qubits with a Tensor Product.
```math
\vert0\rangle \otimes \vert0\rangle = \vert00\rangle
```
If we want to represent two qubits in superposition we can expand it out any other operation:
```math
(\alpha\vert0\rangle + \beta\vert1\rangle)\otimes(\gamma\vert0\rangle + \delta\vert1\rangle)=
```
```math
\alpha \vert0\rangle\otimes\gamma\vert0\rangle + \alpha\vert0\rangle\otimes\delta\vert1\rangle + \beta\vert1\rangle\otimes\gamma\vert0\rangle + \beta\vert1\rangle\otimes\delta\vert1\rangle=
```
```math
\alpha\gamma\vert00\rangle + \alpha\delta\vert01\rangle + \beta\gamma\vert10\rangle + \beta\delta\vert11\rangle
```
Now the probability of measuring 00 is the magnitude squared of the coefficient of the 00 state.
```math
Prob(measuring\vert00\rangle)=\vert\alpha\gamma\vert^2
```
```math
Prob(measuring\vert01\rangle)=\vert\alpha\delta\vert^2
```
```math
Prob(measuring\vert10\rangle)=\vert\beta\gamma\vert^2
```
```math
Prob(measuring\vert11\rangle)=\vert\beta\delta\vert^2
```

Short hand notations:
```math
\vert0000...0\rangle = \vert0\rangle^{\otimes n} ... where\ n \ is \ number\ of\ 0
```
If wanted to add another qubit to the system all we need to do is tensor it to the end of state.

### Quantum Circuits

Quantum circuit is a diagram that helps us show what gates we apply to which qubit in the system.



In this instance we can X-gate being applied to the second qubit and after that H-gate. At the end we measure all the qubits.

The horizontal is the order in which we apply the gates.
The $\psi$ states are used to represent the state of the system at different points during the algorithm.
```math
\vert\psi_0\rangle = \vert001\rangle
```
```math
\vert\psi_1\rangle= \vert011\rangle
```
```math
\vert\psi_2\rangle= \frac{1}{\sqrt{2}}(\vert001\rangle-\vert011\rangle)
```
```math
\vert\psi_3\rangle= \frac{1}{\sqrt{2}}(\vert100\rangle-\vert110\rangle)
```
```math
\vert\psi_4\rangle will\ be\ \vert100\rangle \ \frac{1}{2}\ of \ time, \ and \ \vert110\rangle \frac{1}{2}\  of \ time.
```
### Multi Qubit Gates

#### CNOT

The CNOT gate acts on two qubits. One is the target and and the other control qubit.
The CNOT gate applies an X gate to the target qubit if the control qubit is a 1. If control is 0 it does nothing.

Another way of describing the is as a generalization of the classical gate, since the action of the gate may be summarized as $\vert A,B\rangle\rightarrow\vert A,B⊕A\rangle$ , where ⊕ is addition modulo two, which is exactly what the gate does. That is, the control qubit and the target qubit are ed and stored in the target qubit. Yet another way of describing the action of the is to give a matrix representation, as shown in the bottom right of Figure 1.6. You can easily verify that the first column of $U_{CN}$ describes the transformation that occurs to $\vert00\rangle$, and similarly for the other computational basis states, $\vert01\rangle$ , $\vert10\rangle$ , and $\vert11\rangle$. As for the single qubit case, the requirement that probability be conserved is expressed in the fact that $U_{CN}$ is a unitary matrix, that is, $U^{\dagger}_{CN}U_{CN} = I$.

Using three CNOT gates on two qubits interchangeably we can implement SWAP gate.

#### Toffoli Gate

Toffoli gate is similar to CNOT gate but it has 2 control qubits.
If both control qubits are 1 we apply X-gate to the target qubit. If only one is a 0 we do nothing.

#### Controlled versions of our single qubit gates

Using CNOT gates we can create controlled versions of our single qubit gates.
We also have CY, CZ, CS, CT, CH, ... We write the gates as seen eg. Controlled Y = CY.

### Measuring Singular Qubits

Now that we have multiple qubits. How do we measure a singular qubit.

Let's say we want to measure the probability of the second qubit as a 1. We do this by looking at all the superposition sets where second qubit is a 1 and sum up their measurements.

##### But how do we know what the state collapses to after we measure the qubit?

Once we measure the qubit it collapses its superposition and becomes the measurement.
Let's say we measure the second qubit as a one. Now we get rid of all states that don't have 1 as the second qubit. But the new probabilities do not add up to 1 because we removed some of them. Now we have to use a normalization constant.
```math
\vert\psi_1\rangle = A(x\vert10\rangle + y\vert11\rangle)
```
```math
\vert Ax \vert^2 +\vert Ay \vert^2=1
```
```math
A = \sqrt{\frac{1}{x^2 + y^2}}
```

A is normalization constant and $\vert\psi_1\rangle$ is a new state after the measurement.
This example is for two qubits but it cam be used for multiple qubits.

```math
A = \frac{1}{\sqrt{x_1^2 + x_2^2 + ....+ x_n^2}}
```
Where $x_1,x_2,...,x_n$ are factors of the measured superposition.
The unmeasured states are changed to 0 and the other measured states are multiplied by constant A.

### Quantum entanglement

In this state $\vert\psi\rangle = \frac{1}{\sqrt{2}}(\vert00\rangle+\vert11\rangle)$ if we measure one of the qubits as a 0 we then know that the other qubit would collapse into a 0. Or if we measure one of the qubits as a 1 the other one would collapse into a 1.  So by measuring one of the qubits we know the sate of the other qubit and this is called entanglement.

A state is entangled if it cannot be factored into the tensor product of individual qubits.
This means when the qubits are entangled they depend on each other to determine their state.

There are two types of entangled states: Maximally entangled states and partially entangled states.

Qubits are **maximally entangled** if by measuring one of the qubits we can determine with certainty if the other qubit will be measured as 0 or 1.
#### Bell States
Are maximally entangled states of two qubits:
```math
|\Phi^+\rangle = \frac{1}{\sqrt{2}} \left( |00\rangle + |11\rangle \right)
```
```math
|\Phi^-\rangle = \frac{1}{\sqrt{2}} \left( |00\rangle - |11\rangle \right)
```
```math
|\Psi^+\rangle = \frac{1}{\sqrt{2}} \left( |01\rangle + |10\rangle \right)
```
```math
|\Psi^-\rangle = \frac{1}{\sqrt{2}} \left( |01\rangle - |10\rangle \right)
```

Qubits are **partially entangled** if by measuring one of the qubits, the amplitudes of the other are effected.

### Phase Kickback

Phase Kickback happens if we have a state $\vert v\rangle$ that is an eigenvector of gate $U$. By applying a controlled-U gate with  $\vert v\rangle$ as the target, we can 'kick' the phase onto the control qubit.

All eigenvalues of quantum computer can be represented as $e^{i\theta}$ .
```math
U\vert v\rangle=e^{i\theta}\vert v\rangle
```
After applying the $U$ gate  onto $\vert v\rangle$  we realize that $\vert v\rangle$ state remains unchanged and that  $e^{i\theta}$ has been applied as the relative phase to the control bit.
```math
\vert\psi_1\rangle=(\ \vert0\rangle+\vert1\rangle\ )\ \vert v\rangle
```
```math
\vert\psi_2\rangle=(\ \vert0\rangle+e^{i\theta}\vert1\rangle\ )\ \vert v\rangle
```
### Superdense Coding

Quantum protocol that allows us to send two bits of classical information ( 00, 01, 10, 11 ) using 1 qubit.

Lets say that Alice wants to send Bob two classical bits. Alice and Bob both have one qubit. Depending on what two bits Alice wants to send she will preform some operations on her qubit.
 The first qubit is Alice's and the second one is Bobs.
```math
\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle+\vert11\rangle\ )
```
Alice wants to send 00: she does nothing, Qubits: $\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle+\vert11\rangle\ )$
Alice wants to send 01: she applies X-gate to her qubit, Qubits: $\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert10\rangle+\vert01\rangle\ )$
Alice wants to send 10: she applies Z-gate to her qubit, Qubits: $\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle-\vert11\rangle\ )$
Alice wants to send 11: she applies both X and Z-gate to her qubit, Qubits: $\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert10\rangle-\vert01\rangle\ )$

Then she sends her qubit to Bob so he now has both.
Bob then applies a CNOT with the first qubit as a control and the second as a target. Then he applies a Hadamard gate to the left qubit and gets the sates that Alice wanted to send, all he has to do is measure the qubits.

```math
\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle+\vert11\rangle\ ) \xrightarrow{CNOT} \vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle+\vert10\rangle\ ) \xrightarrow{H} H\vert+\rangle\vert0\rangle = \vert00\rangle
```
```math
\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert10\rangle+\vert01\rangle\ ) \xrightarrow{CNOT} \vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert11\rangle+\vert01\rangle\ ) \xrightarrow{H} H\vert+\rangle\vert1\rangle = \vert01\rangle
```
```math
\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle-\vert11\rangle\ ) \xrightarrow{CNOT} \vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert00\rangle-\vert10\rangle\ ) \xrightarrow{H} H\vert-\rangle\vert0\rangle = \vert10\rangle
```
```math
\vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert10\rangle-\vert01\rangle\ ) \xrightarrow{CNOT} \vert\psi\rangle=\frac{1}{\sqrt{2}}(\ \vert11\rangle-\vert01\rangle\ ) \xrightarrow{H} H\vert-\rangle\vert1\rangle = \vert11\rangle
```

### Quantum functions

Since the operations preformed on quantum computers must be reversible if we wanted to apply a function on a quantum computer, the function must be reversible.

To do this we use the same techniques for making classical gates reversible. A standard quantum function looks like this:


```math
U_f\vert x\rangle\vert y\rangle= \vert x\rangle\vert y\ \otimes\ f(x)\ \rangle
```
If we set $\vert y\rangle$ state to $\vert 0\rangle$ we get $0\otimes f(x)$ which is $f(X)$ . If we set $\vert y\rangle$ state to 1 we get $1\otimes f(x)$ which equals to $\overline{f(x)}$ .
$\otimes$ is the XOR operation where 00->0, 01->1, 10->1, 11->0.

If we set $\vert y\rangle$ to the state of minus $\vert -\rangle$ instead of function output $f(x)$ being XOR'd with $\vert -\rangle$ register, a phase of $(-1)^{f(x)}$ was applied to the input to the function $(\vert x\rangle)$.
### No-cloning Theorem

On quantum computers if we have a qubit in an unknown state $\vert \psi\rangle = \alpha\vert 0\rangle+\beta\vert 1\rangle$ , we cannot clone the sate of $\vert \psi\rangle$ if we do not know the values of $\alpha$ and $\beta$. If we were to measure the qubit like we do in a classical computer, the qubit will change to 0 or a 1.

If we know the sates of $\alpha$ and $\beta$ we can easily copy the qubit by applying the needed gates.


##  References

+ YouTube: Quantum Soar : Quantum Computing Course: 1.1 - 1.
+ Kvantne in Računalniske Tehnologije by Rok Žitko, 2017
+ www.quantum-inspire.com
+ Nielse-Chuang: Quantum Computing and Quantum Information,
+ https://jonathan-hui.medium.com/qc-programming-with-quantum-gates-2-qubit-operator-871528d136db
