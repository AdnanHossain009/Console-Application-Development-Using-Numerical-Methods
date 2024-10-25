# Console-Application-Development-Using-Numerical-Methods
<body>
    <h1>Gaussian Elimination Method</h1>
Gaussian elimination is a method used in solving systems of linear equations; it converts any given arbitrary system into one whose solution is immediately obvious. It works in two phases: <b>forward elimination</b> and <b>back substitution</b>.

Given a system of equations in matrix form:
<div class="equation">A * x = b</div>
where:
<ul>
        <li><b>A</b> is an <i>n × n</i> matrix of coefficients.</li>
        <li><b>x</b> is the vector of unknowns.</li>
        <li><b>b</b> is the right-hand side vector.</li>
    </ul>

<h2>Steps of Gaussian Elimination</h2>
Gaussian elimination works by transforming the matrix <b>A</b> into an upper triangular matrix, where all elements below the main diagonal are zero. This is accomplished by performing a sequence of row operations.

<h2>1. Forward Elimination</h2>
<p>In the forward elimination phase, we are transforming the matrix to an upper triangular form.</p>
<ol>
<li><b>Pivoting</b>: For each column choose a pivot element-a rule of thumb is to take a non-zero element from the diagonal. If this is zero, perform row changes so that the diagonal element is non-zero. Pivoting minimizes numerical instability.
<li><b>Eliminate</b>: For all rows that lie below the pivot, eliminate the entries in the current column by applying row operations. More formally, for every row <i>i</i> that is lower than the pivot row <i>k</i>, it updates the row according to
            <div class="equation">Row<sub>i</sub> = Row<sub>i</sub> - (a<sub>ik</sub> / a<sub>kk</sub>) * Row<sub>k</sub></div>
where:
            <ul>
                <li><i>a<sub>ik</sub></i> is the element in row <i>i</i> and column <i>k</i>.</li>
<li><i>a<sub>kk</sub></i> is the pivot element.</li>
            </ul>
        </li>
    </ol>
This process is then repeated for each column, creating zeros below each successive pivot. When all the rows have been used, the matrix will have become upper triangular.

<h2>2. Back Substitution</h2>
    <p>Once <b>A</b> has been put into upper triangular form, the unknowns can be solved from the last row upwards.
<ol>
        <li><b>Solve the last variable</b>: Now, the last equation has only one unknown that can be solved directly.
        <li><b>Substitute back</b>: Substitute the value of the solved variable into the preceding equations in reverse order and solve for the other unknowns.
For instance, if the following system has been transformed:,
    $$\begin{equation*}
        \begin{aligned}
            a_{nn}x_n &= b'_n\\
            a_{(n-1)(n-1)}x_{n-1} + a_{(n-1)n}x_n &= b'_{n-1}\\
            .
    $$.
a<sub>11</sub> x<sub>1</sub> + a<sub>12</sub> x<sub>2</sub> +. + a<sub>1n</sub> x<sub>n</sub> = b'<sub>1</sub>
        </pre>
    </div>
    <p>we solve for <i>x<sub>n</sub></i> in the last equation, then substitute back to find <i>x<sub>n-1</sub></i>, <i>x<sub>n-2</sub></i>, ., <i>x<sub>1</sub></i>.</p>

    <h2>Gaussian Elimination Algorithm</h2>
    <ol>
<li><b>Forward Elimination</b>:
            <ul>
                <li>For each column <i>k = 1, 2, ., n-1</i>:</li>
                <li>Pivot (if necessary) by swapping rows.</li>
<li>For each row <i>i = k+1, k+2, ., n</i>:</li>
                <div class="equation">Row<sub>i</sub> = Row<sub>i</sub> - (a<sub>ik</sub> / a<sub>kk</sub>) * Row<sub>k</sub></div>
            </ul>
</li>
        <li><b>Back Substitution</b>:
            <ul>
                <li Begin with the last row and solve for <i>x<sub>n</sub></i>.</li>
<li>Substitute the solution value for <i>x<sub>n</sub></i> into the previous equation and solve for <i>x<sub>(n-1)</sub></i> repeating in this fashion until <i>x<sub>1</sub></i> is solved.</li>
            </ul>
        </li>
    </ol>

    <h2>Example</h2>
    <p>Consider the system:
<div class="equation">
<pre>
        2x + 3y + z = 1
        4x + y - 2z = -2
        -2x + 5y + 7z = 3
       </pre>
    </div>
<p><b>1. Forward Elimination:</b> This system is to be reduced to an upper triangular form using row operations.</p>
    <p><b>2. Back Substitution:</b> Solve for <i>z</i> from the last equation, then by substitution solve for <i>y</i>, and finally <i>x</i>.</p>

<h2>Advantages and Limitations</h2>
<ul>
  <li><b>Advantages</b>: Gaussian elimination is a systematic method that works for any invertible matrix.</li>
• <b>Limitation</b>: The method can be computationally expensive for large matrices. Gaussian elimination may also be prone to numerical instability, in particular if the magnitudes of the pivot elements are close to zero.

<body>
    <h1>Gauss-Jordan Elimination Method</h1>
Gauss-Jordan Elimination Gauss-Jordan elimination is an extended form of Gaussian elimination for the solution of systems of linear equations. In this process, a matrix is brought to its RREF where every leading entry must be 1, and all entries in any column containing a leading entry must be zero everywhere else. Gauss-Jordan elimination eliminates the variables above and below each pivot to create a thoroughly simplified matrix from which one can read directly from the matrix.

Given a system of linear equations in matrix form: 
$$A * x = b$$ 
where: 
• A is an n×n matrix of coefficients; 
• x is a vector of unknowns.
• <b>b</b> is the right-hand side vector.
•
Steps of Gauss-Jordan Elimination
Gauss-Jordan elimination consists of two major steps: <b>forward elimination</b> and <b>backward elimination</b> in order to have zeros elsewhere in each column that contains a leading entry.
1. Forward Elimination
• <b>Pivoting</b>: Choose a pivot for each column - that is, a non-zero entry in the diagonal. If the entry in the diagonal is zero, then the row is exchanged to make it nonzero. The stability is maintained this way.
• <b>Make Pivot Unity</b>: Scale the row so that every element is divided by the pivotal element to make it 1.
• <b>Eliminate Below</b>: For each row below the pivot, add multiples of the pivot row to the current row so as to force the entries in the pivot column to zero.
    </ol>
    The resulting matrix is one whose entries below each pivot are all zero, as in the result of Gaussian elimination.

    <h2>2. Backward Elimination</h2>
After forward elimination, further simplification to get a reduced row echelon form is as follows: 
    The steps involved are as follows: 
a. <b>Eliminate Above</b>: For each pivot, clear the entry above by subtracting the appropriate multiple of the pivot row.
<li><b>Direct Solution</b>: If all columns containing leading entries have zeros elsewhere, then each variable can be read directly from the matrix.</li >
    </ol

    <h2>Gauss-Jordan Elimination Algorithm</h2>
    <ol>
        <li><b>Forward Elimination</b>:
            <ul>
<li>For each column<i>k = 1, 2, ., n</i>:</li>
                <li>Select the pivot element, and swap the rows if needed.
<li>Scale the pivot row to make the pivot element equal to 1.</li>
                <li>For each row <i>i</i> below the pivot, update <i>Row<sub>i</sub></i> by subtracting the appropriate multiple of the pivot row to make <i>a<sub>ik</sub> = 0</i>.</li>
</ul>
        </li>
        <li><b>Backward Elimination</b>:
            <ul>
• Starting from the last pivot and going up, use row operations on the entries above each pivot to convert it to zero. 
            </ul>
        </li>
    </ol

    <h2>Example</h2>
    <p>Consider the system:
<div class="equation">
        <pre>
        2x + y - z = 8
        -3x - y + 2z = -11
        -2x + y + 2z = -3
        </pre>
    </div>
<p><b>1. Forward Elimination:</b> Select the pivot for the first row and, if it isn't already 1, set the row divided by its entry equal to 1, then use it to eliminate the entries below the pivot. Repeat for each pivot until the matrix is in row echelon form.
<p><b>2. Backward Elimination:</b> For each pivot, make the entries above zero and obtain a reduced row echelon form in which variables can be read directly.</p>

<h2>Pros and Cons</h2>
<ul>
<li><b>Advantages</b>: Gauss-Jordan elimination reduces a matrix to its most simplified form, from which the solutions can be directly read without any further substitution. This makes it quicker and more systematic for solving systems compared to Gauss' elimination methods.
</ul>
</body>
</html>

<body>
    <h1>Matrix Inversion</h1>
Matrix inversion is among the basic operations in linear algebra and is defined as the calculation of a matrix, A-1, known as the inverse of matrix A, such that its multiplication with A results in the identity matrix I. The identity matrix is a square matrix with 1s on the diagonal and zeroes elsewhere.

Definition
Given a square matrix A of order n, its inverse A-1 fulfills the following requirement: $AA^{-1} = A^{-1} A = I$ where I is the n × n identity matrix. Conditions for Invertibility
Not all matrices possess inverses. A square matrix A is said to be invertible (or non-singular) if:
    Determinant Condition: The determinant of A is non-zero:
        The equation is det(A) ≠ 0
</div>
</li>
<li><b>Square Matrix</b>: The matrix should be square in nature, i.e., it must have the same number of rows as well as columns.
</li>
</ul>
<p"When the value of determinant is zero, then the matrix is said to be singular and its inverse does not exist.

Methods for Finding the Inverse
    There are several methods for calculating the inverse of a matrix:
    Gauss-Jordan Elimination:
<p>This method involves augmenting the matrix <i>A</i> with the identity matrix <i>I</i> and applying row operations to transform <i>A</i> into <i>I</i>. The augmented part will then become <i>A<sup>-1</sup></i>.</p>
        </li>
        <li><b>Adjoint Method</b>:
The inverse can also be calculated with the following formula: 
            <div class="equation">
                A<sup>-1</sup> = <span style="text-decoration: overline;">1</span> det(A) · adj(A)
            </div>
where is the adjugate (or adjoint) of. The adjugate is obtained by taking the transpose of the cofactor matrix.
        </li>
        <li><b>Using the Matrix of Minors</b>:
<p>The direct determinant calculation of the matrix and minors, cofactors, and adjugate. This approach is computationally expensive for large matrices.</p>
        </li>
        <li><b>LU Decomposition:</b>
Decompose the matrix A into a lower triangular matrix L and an upper triangular matrix U, such that A = LU. Find the inverses of L and U separately. Multiply them to obtain A-1.  

        </li>
    </ol>

    <h2>Example</h2>
Consider the following matrix: 
    $A = \left(\begin{array}{cc} 
    4 & 7 \\ 
    2 & 6 
    \end{array}\right)$
    <ol>
    <li><b>Find the Determinant</b>:
<div class="equation">
                det(A) = (4)(6) - (7)(2) = 24 - 14 = 10
            </div>
        </li>
• <b>Find the Adjugate</b>:
            <div class="equation">
                adj(A) = \begin{pmatrix}
                6 & -7
-2 & 4
                \\end{pmatrix}
            </div>
        </li>
        <li><b>Find the Inverse</b>:
<div class="equation">
                A<sup>-1</sup> = <span style="text-decoration: overline;">1</span> 10 · \\\\begin{pmatrix}
                6 & -7 \\\\\"]
-2 & 4
                \\end{pmatrix} = \\begin{pmatrix}
                0.6 & -0.7 \\
-0.2 & 0.4
                \\end{pmatrix}
            </div>
        </li>
    </ol>
<h2>Matrix Inversion Applications</h2>
    <p>There are several applications of matrix inversion in various fields, such as: </p>
    <ul>
        <li><b>Solution of Linear Systems</b>: In the case of systems of linear equations, if <i>A</i> is a matrix containing the coefficients of the variables involved, the solution <i>A<sup>-1</sup>b</i> can be determined using the formula below:
            <div class="equation">
x = A<sup>-1</sup>b
            </div>
            <p>where <i>b</i> is the vector of constants.
• Computer Graphics: In three-dimensional graphics, it works out the inverses for matrix purposes to perform transformations and find the position of objects.
• Control Systems: In control theory, the process of inverting a matrix is highly instrumental in systems analysis and also in controller design.
• Statistics: In multivariate statistics, the inverse of the covariance matrix features in many analyses.
</ul>

Limitations
<ul>
<li><b>Computational Complexity</b>: The inverse of large-size matrices involves heavy computational complexity and can lead to numerical instability.
<b>Singular Matrices</b>: If a matrix is singular, then it cannot be used in those types of calculations which require its inverse.
<ul>
<h2>Conclusion</h2>
    <p>Matrix inversion is a fundamental concept in linear algebra and finds many applications in mathematics, engineering, computer science, and more. Finding and utilizing matrix inverses is key to problem-solving involving both linear systems and transformations.

    <!DOCTYPE html>
<html lang="en">
<body>
    <h1>Bisection Method</h1>
<p>The Bisection method is a straightforward and stable numerical method for computing the roots of a continuous function.    It works especially fine when a function is continuous on a closed interval and the root is guaranteed to exist between two points in that interval. The method makes use of the so-called Intermediate Value Theorem that says: if a function changes the sign over an interval, then it has at least one root in that interval.</p>     <h2>Steps of the Bisection Method</h2>

    <ol>
<li><b>Selection of Starting Points</b>:
            <p>There should be two starting points, <i>a</i> and <i>b</i>, such that the function values at both points satisfy <i>f(a) · f(b) < 0</i>. This will mean that there exists at least one root within the interval <i>[a, b]</i>.</p>
        </li>
<li><b>Calculate Midpoint</b>: 
            <p>Compute the midpoint <i>c</i> of the interval:</p>
            <div class="equation">c = (a + b) / 2</div>
        </li>
        <li><b>Evaluate Function at Midpoint</b>:
Check the value of the function at the midpoint: f(c).
        </li>
        <li><b>Check for Root</b>:
            <p>If f(c) = 0, then c is the root, and the method terminates.
If <i>f(c) ≠ 0</i>, determine for which subinterval(s) to continue:
            <ul>
                <li>If <i>f(a) · f(c) < 0</i>, then the root is in <i>[a, c]</i>. Let <i>b = c</i>.</li>
• <i>f(c) · f(b) < 0</i>>, then the root lies in <i>[c, b]</i>. Set <i>a = c</i> .
            </ul>
        </li>
        <li><b>Repeat</b>:
<p>Repeat steps 2 to 4 until the desired accuracy is obtained. In general this is when the width of the interval |b - a| is less than a given tolerance ε, or, alternatively, when f is sufficiently close to zero.</p>
        </li>
    </ol>
    <h2>Example</h2>

Let's consider the function f(x) = x² - 4 and find the root in the interval [0, 5].
    <ol>
        <li><strong>Initial Points</strong>: a = 0, b = 5 since f(0) < 0 and f(5) > 0.</li>
        <li><strong>First Iteration</strong>:
<ul>
                <li>Compute <i>c = (0 + 5) / 2 = 2.5</i>.</li>
                <li>Compute <i>f(2.5) = (2.5)² - 4 = -1.75</i>.</li>
<li>Since <i>f(0) · f(2.5) < 0</i>, update <i>b = 2.5</i>.</li>
            </ul>
        </li>
        <li><b>Second Iteration</b>:
            <ul>
• Compute c = (0 + 2.5)/2 = 1.25.
 • Find f(1.25) = (1.25)² - 4 = -3.4375.
• Update b = 1.25 (since f(0) · f(1.25) < 0).
            </ul>
        </li>
        <li><b>Following Iterations</b>:
<p>Continue iterations until the interval is small enough, thereby converging to the root <i>x = 2</i>.</p>
        </li>
    </ol>
    <h2>Advantages and Limitations</h2>

    <ul>
        <li><b>Advantages</b>:
• The Bisection Method is certain to converge provided the initial interval has been chosen correctly. • It has a very simple formulation and hence easy to understand.
•	 It can be applied to any continuous function.
            </ul>
        </li>
        <li><b>Limitations</b>: 
            <ul>
• The method might be slow to converge, especially if the function has roots close to each other. • It applies only to functions that change sign over the interval.
• The method needs initial guesses that bracket the root.
            </ul>
        </li>
    </ul>
Bisection is perhaps the most basic numerical method, but it is at the same time a foundation of other, usually more complex root finding methods.
