# Console-Application-Development-Using-Numerical-Methods

<body>

<p>This project, completed by our group of three members, presents a console application that implements various numerical methods for solving mathematical and engineering problems. Each algorithm is structured to be modular and allows for interactive user input.</p>
    
<h2>Objective</h2>
    <p>The main goal of this project is to collaboratively develop a console application that applies different numerical methods to solve systems of linear and non-linear equations, differential equations, and matrix inversion. The project highlights our understanding of numerical algorithms and our skills in programming and collaborative development.</p>

<h2>Features</h2>
    <ul>
        <li><strong>Solution of Linear Equations:</strong> Includes Jacobi, Gauss-Seidel, Gauss elimination, Gauss-Jordan elimination, and LU factorization methods.</li>
        <li><strong>Solution of Non-linear Equations:</strong> Includes the bisection method, false position method, secant method, and Newton-Raphson method.</li>
        <li><strong>Solution of Differential Equations:</strong> Uses the Runge-Kutta method.</li>
        <li><strong>Matrix Inversion:</strong> Provides a matrix inversion solution through numerical computation.</li>
    </ul>

<h2>Repository Structure</h2>
    <p>The code for each method is organized within individual modules, allowing for flexibility and ease of testing. A README section explains each method, the algorithm behind it, and sample code output. The project also includes a demonstration video linked below.</p>
    
<h2>Video Presentation</h2>
    <p>A 2-minute video demonstrating the functionality of this application can be accessed <a href="your-video-link-here">here</a>.</p>

<h2>Here is the full explanaton of the algorithm being used in each method and also detailed explanation is also included.</h2>

<h1>1. Jacobi Iterative Method</h1>
    <p>The Jacobi method is an iterative algorithm to solve a system of linear equations of the form:</p>
    <div class="equation">A * x = b</div>
    
<p>where:</p>
<ul>
        <li><b>A</b> is an <i>n × n</i> matrix of coefficients.</li>
        <li> <b>x</b> is the vector of unknowns.
        <li> <b>b</b> is the right-hand side vector.
</ul>
 
<p>This method computes each component of <b>x</b> independently in each step using the previous values, thus it being simpler but often much slower than the Gauss-Seidel method.</p>

<h2> Key Assumptions for the Jacobi Method</h2>
For convergence, the Jacobi method assumes that:
<ul>
        <li><b>A</b> will be a square matrix.</li>
        <li><b>A</b> must be diagonally dominant.</li>
</ul>

<h3> Diagonal Dominance</h3>
Diagonal dominance is a sufficient condition for convergence and is defined by :
<div class="equation">|a<sub>ii</sub>| > ∑<sub>j ≠ i</sub> |a<sub>ij</sub>|</div>
    for all row <i>i</i>.

<h2>Jacobi Method Algorithm</h2>
    <ol>
        <li><b>Initialization</b>: First take an initial guess <b>x<sup>(0)</sup></b>.</li>
        <li><b>Iteration</b>:
            <ul>
<li>For each <i>i = 1, 2, ., n</i>:</li>
            </ul>
            <div class="equation">x<sub>i</sub><sup>(k+1)</sup> = (1 / a<sub>ii</sub>) * ( b<sub>i</sub> - ∑<sub>j ≠ i</sub> a<sub>ij</sub> x<sub>j</sub><sup>(k)</sup> )</div>
<li><b>Convergence Check</b>: Continue iterating until the solution converges, usually when:
            <div class="equation">||x<sup>(k+1)</sup> - x<sup>(k)</sup>|| < tolerance</div>
        </li>
    </ol>

<h2>Convergence of Jacobi Method</h2>
Convergence of the Jacobi method is guaranteed when:
• A is diagonally dominant.
• A is symmetric positive definite.
If these conditions are violated, it may turn out to be slowly convergent or even divergent for the Jacobi method.

<h2>Example</h2>
    <p>Considering the following system for sample test:
<div class="equation">
         <pre>
        10a + 2b  - c   + 3d  + 4e = 30
        3a  + 12b + 4c  - d   + 2e = 20
        2a  + b   + 11c - 2d  + 3e = 10
        a   + 2b  - 3c  + 10d + e  = 15
        4a  - b   + 3c  + 2d  + 9e = 25
       </pre>
</div>
<p>To solve the system the user needs to enter the number of variables, coefficient of the matrix, the constant terms, initial guesses for the variables, the tolerance for convergence, and the maximum number of iterations allowed.</p>

<h2>Advantages of the Jacobi Method</h2>
<ul>
        <li>Each component of <b>x</b> can be computed independently from the other components, which means that this is a method that can easily be parallelized.
        <li>Easy to code and analyze.
        <li>This is a good method for diagonally dominant matrices.
</ul>

<h2>Disadvantages of the Jacobi Method</h2>
<ul>
<li>Normally, it is slower compared to the Gauss-Seidel method.</li>
<li>If matrix A is either not diagonally dominant or symmetric positive definite, convergence cannot be guaranteed.</li>
<li> It is a very memory-consuming approach since it will store current and previous iteration values of x.</li>
</ul>

<h1>2. Gauss-Seidel Iterative Method</h1>
    <p>The Gauss-Seidel method is an iterative technique for solving a system of linear equations of the form:</p>
    <div class="equation">A * x = b</div>
    
<p>where:</p>
    <ul>
        <li><b>A</b> is an <i>n × n</i> matrix of coefficients.</li>
        <li><b>x</b> is the vector of unknowns.</li>
        <li><b>b</b> is the right-hand side vector.</li>
    </ul>
    
<p>This method is commonly applied to large, sparse systems of equations and is often an improvement over the Jacobi method, as elements of <b>x</b> are updated immediately after computation, typically leading to faster convergence.</p>

<h2>Key Assumptions for the Gauss-Seidel Method</h2>
    <p>For convergence, the Gauss-Seidel method generally assumes:</p>
    <ol>
        <li><b>A</b> should be a square matrix.</li>
        <li><b>A</b> must be either diagonally dominant or symmetric positive definite.</li>
    </ol>

<h3>Diagonal Dominance</h3>
    <p>Diagonal dominance is a sufficient but not necessary condition for convergence and is defined by:</p>
    <div class="equation">|a<sub>ii</sub>| > ∑<sub>j ≠ i</sub> |a<sub>ij</sub>|</div>
    for every row <i>i</i>.

<h2>Gauss-Seidel Method Derivation</h2>
    <p>To obtain the Gauss-Seidel method, we decompose <b>A</b> into three parts:</p>
    <div class="equation">A = L + D + U</div>
    
<p>where:</p>
    <ul>
        <li><b>D</b> is a diagonal matrix containing the diagonal elements of <b>A</b>,</li>
        <li><b>L</b> is the lower triangular matrix with elements below the diagonal,</li>
        <li><b>U</b> is the upper triangular matrix with elements above the diagonal.</li>
    </ul>
    
<p>The system <b>A * x = b</b> can be rearranged to update <b>x</b> as:</p>
    <div class="equation">(L + D) * x<sup>(k+1)</sup> = b - U * x<sup>(k)</sup></div>
    
<p>Solving for <b>x<sup>(k+1)</sup></b> gives the iteration formula:</p>
    <div class="equation">x<sup>(k+1)</sup> = (L + D)<sup>-1</sup> * (b - U * x<sup>(k)</sup>)</div>

<h2>Example</h2>
    <p>Consider the following system for sample test:
<div class="equation">
         <pre>
        10a + 2b  - c   + 3d  + 4e = 30
        3a  + 12b + 4c  - d   + 2e = 20
        2a  + b   + 11c - 2d  + 3e = 10
        a   + 2b  - 3c  + 10d + e  = 15
        4a  - b   + 3c  + 2d  + 9e = 25
       </pre>
</div>

<h2>Convergence of Gauss-Seidel Method</h2>
    <p>The Gauss-Seidel method typically converges faster than the Jacobi method, especially for systems where:</p>
    <ul>
        <li><b>A</b> is diagonally dominant.</li>
        <li><b>A</b> is symmetric positive definite.</li>
    </ul>
    <p>However, if these conditions are not met, the Gauss-Seidel method may converge slowly or even diverge.</p>

<h2>Advantages of the Gauss-Seidel Method</h2>
    <ul>
        <li>Typically faster convergence than the Jacobi method for well-conditioned systems.</li>
        <li>Easy to implement and efficient for large, sparse matrices.</li>
        <li>Requires only one matrix storage, reducing memory usage.</li>
    </ul>

<h2>Disadvantages of the Gauss-Seidel Method</h2>
    <ul>
        <li>Convergence is not guaranteed for all matrices, especially if not diagonally dominant or symmetric positive definite.</li>
        <li>Can diverge or converge slowly for poorly conditioned systems.</li>
        <li>Not easily parallelizable due to its sequential updating of <b>x</b> values.</li>
    </ul>

        
<h1>3. Gaussian Elimination Method</h1>
Gaussian elimination is a method used to solve systems of linear equations; it converts any given arbitrary system into one whose solution is immediately obvious. It works in two phases: <b>Forward Elimination</b> and <b>Back substitution</b>.

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
<li><b>Pivoting</b>: For each column we have to choose a pivot element-a rule of thumb is to take a non-zero element from the diagonal. If this is zero, perform row changes so that the diagonal element is non-zero. We have used Partila_Pivoting method here which minimizes numerical instability.
<li><b>Eliminate</b>: For all rows that lie below the pivot, we have to eliminate the entries in the current column by applying row operations. More formally, for every row <i>i</i> that is lower than the pivot row <i>k</i>, it updates the row according to
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
For instance, if the following system has been transformed:
            
<div class="equation">
    <span>a<sub>nn</sub>x<sub>n</sub> = b<sub>n</sub></span>
    <span>a<sub>(n-1)(n-1)</sub>x<sub>(n-1)</sub> + a<sub>(n-1)n</sub>x<sub>n</sub> = b<sub>(n-1)</sub></span>
    
</div>
a<sub>11</sub> x<sub>1</sub> + a<sub>12</sub> x<sub>2</sub> +. + a<sub>1n</sub> x<sub>n</sub> = b<sub>1</sub>
        </pre>
</div>
<p>we solve for <i>x<sub>n</sub></i> in the last equation, then substitute back to find <i>x<sub>n-1</sub></i>, <i>x<sub>n-2</sub></i>, ., <i>x<sub>1</sub></i>.</p>

<h2>Example</h2>
    <p>Suppose considering the following system that we solved during sample test :
<div class="equation">
        <pre>
        10a + 2b  - c   + 3d  + 4e = 30
        3a  + 12b + 4c  - d   + 2e = 20
        2a  + b   + 11c - 2d  + 3e = 10
        a   + 2b  - 3c  + 10d + e  = 15
        4a  - b   + 3c  + 2d  + 9e = 25
       </pre>
    </div>
<p><b>1. Forward Elimination:</b> This system is to be reduced to an upper triangular form using row operations.</p>
    <p><b>2. Back Substitution:</b> Solve for <i>e</i> from the last equation, then by substitution solve for <i>d</i>,then by substitution and solve <i>c</i>,then by substitution and solve <i>b</i> and finally <i>a</i>.</p>

<h2>Advantages and Limitations</h2>

<ul>
    <li><b>Advantages</b>: Gaussian elimination is a systematic method that works for any invertible matrix.</li>
    <li><b>Limitation</b>: The method can be computationally expensive for large matrices. Gaussian elimination may also be prone to numerical instability, in particular if the magnitudes of the pivot elements are close to zero.</li>
</ul>

<h1>4. Gauss-Jordan Elimination Method</h1>
Gauss-Jordan Elimination is an extended form of Gaussian elimination for the solution of systems of linear equations.So after eliminating the variables above the pivot in the "Gauss-Jordan elimination" we eliminate the variables below each pivot to create a thoroughly simplified matrix from which one can read directly from the matrix.

Steps of Gauss-Jordan Elimination
Gauss-Jordan elimination consists of two major steps: <b>forward elimination</b> and <b>backward elimination</b> in order to have zeros elsewhere in each column that contains a leading entry.
<h2>1. Forward Elimination</h2><br>
<ul>
    <li><b>Pivoting</b>: Choose a pivot for each column - that is, a non-zero entry in the diagonal. If the entry in the diagonal is zero, then the row is exchanged to make it nonzero. The stability is maintained this way.</li>
    <li><b>Make Pivot Unity</b>: Scale the row so that every element is divided by the pivotal element to make it 1.</li>
    <li><b>Eliminate Below</b>: For each row below the pivot, add multiples of the pivot row to the current row so as to force the entries in the pivot column to zero.</li>
</ul>
The resulting matrix is one whose entries below each pivot are all zero, same result as in the Gaussian elimination.

<h2>2. Backward Elimination</h2>
After forward elimination, further simplification to get a reduced row echelon form is as follows: 
    The steps involved are as follows: 
    <ul>
    <li><b>Eliminate Above</b>: For each pivot, clear the entry above by subtracting the appropriate multiple of the pivot row.</li>
    <li><b>Direct Solution</b>: If all columns containing leading entries have zeros elsewhere, then each variable can be read directly from the matrix.</li >
    </ul>

<h2>Gauss-Jordan Elimination Algorithm</h2>
    <ol>
        <li><b>Forward Elimination</b>:
            <ul>
<li>For each column <i>k = 1, 2, ., n</i>:</li>
                <li>Select the pivot element, and swap the rows if needed.
<li>Scale the pivot row to make the pivot element equal to 1.</li>
                <li>For each row <i>i</i> below the pivot, update <i>Row<sub>i</sub></i> by subtracting the appropriate multiple of the pivot row to make <i>a<sub>ik</sub> = 0</i>.</li>
</ul>
        </li>
        <li><b>Backward Elimination</b>:
            <ul>
                <li>Starting from the last pivot and going up, use row operations on the entries above each pivot to convert it to zero. </li>
            </ul>
        </li>
    </ol

    
<h2>Example</h2>
    <p>Consider the following system for sample test:
<div class="equation">
        <pre>
        10a + 2b  - c   + 3d  + 4e = 30
        3a  + 12b + 4c  - d   + 2e = 20
        2a  + b   + 11c - 2d  + 3e = 10
        a   + 2b  - 3c  + 10d + e  = 15
        4a  - b   + 3c  + 2d  + 9e = 25
       </pre>
</div>
<p><b>1. Forward Elimination:</b> Select the pivot for the first row and, if it isn't already 1, then set the row divided by its entry equal to 1, then use it to eliminate the entries below the pivot. Repeat for each pivot until the matrix is in row echelon form.
<p><b>2. Backward Elimination:</b> For each pivot, make the entries above zero and obtain a reduced row echelon form in which variables can be read directly.</p>

<h2>Pros and Cons</h2>
<ul>
<li><b>Advantages</b>: Gauss-Jordan elimination reduces a matrix to its most simplified form, from which the solutions can be directly read without any further substitution. This makes it quicker and more systematic for solving systems compared to Gauss' elimination methods.
<li><b>Disadvantages</b>: Gaussian elimination has several drawbacks: it can be numerically unstable, has high computational complexity, requires extra memory, often needs pivoting for stability, and is limited to linear systems. It may also lose the original matrix structure and lacks flexibility for specialized problems.
</ul>



<h1>5. LU Factorization Method</h1>
<p>
By LU factorization or LU decomposition, one means the following process of solving systems of linear equations through the decomposition of a matrix into the product of a lower triangular matrix <b>L</b> and an upper triangular matrix <b>U</b>. The latter decomposition is useful when several systems with the same coefficient matrix and different right-hand sides are to be solved.</p>

<p>Given a matrix <i>A</i> in the equation:</p>
    <div class="equation">A * x = b</div>
    <p>we factorize <i>A</i> such that:</p>
    <div class="equation">A = LU</div>
    <p>where:</p>
    <ul>
        <li><b>L</b> is a lower triangular matrix with 1s on the diagonal.</li>
• <b>U</b> is an upper triangular matrix.
</ul>
The problem now boils down to solving two triangular systems, which is computationally easier and by all means allows easy back-substitution.

<h2>Solution of the System</h2>
<p>Once LU decomposition is done, the original system <i>A * x = b</i> is decomposed into two triangular systems:</p>
<ol>
<li><b>Solution of L * y = b</b> for <b>y</b> by forward substitution.</li>
        <li><b>Solution of U * x = y</b> for <b>x</b> by backward substitution.</li>
    </ol>

<h2>LU Factorization Algorithm</h2>
    <p>For an <i>n × n</i> matrix <i>A</i> :</p>
    <ol>
<li><b>For each column k</b> from 1 to <i>n</i>:
            <ul>
                <li>Compute the elements of <i>L</i> in the current column below the pivot.</li>
<li>Compute the elements of <i>U</i> in the current row to the right of the pivot.</li>
            </ul>
        </li>
        <li><b>Solve</b> <i>L * y = b</i> using forward substitution.
<li><b>Solve</b> <i>U * x = y</i> by backward substitution.</li>
    </ol

<h2>Example</h2>
    <p>Consider a system with coefficient matrix <i>A</i>:
    <div class="equation">
        <pre>
        10a + 2b  - c   + 3d  + 4e = 30
        3a  + 12b + 4c  - d   + 2e = 20
        2a  + b   + 11c - 2d  + 3e = 10
        a   + 2b  - 3c  + 10d + e  = 15
        4a  - b   + 3c  + 2d  + 9e = 25
       </pre>
    </div>
    <p>1. Do LU factorization to get <b>L</b> and <b>U</b>.</p>
    <p>2. Solve <i>L * y = b</i> for <i>y</i>.</p>
    <p>3. Substitute <i>y</i> into <i>U * x = y</i> and solve for <i>x</i>.</p>

<h2>Advantages and Limitations</h2>
    <ul>
        <li><b>Advantages</b>: LU factorization is efficient in solving multiple systems with the same matrix <i>A</i>. It also reduces computation time when using matrix inversion methods.</li>
        <li><b>Limitations</b>: LU factorization may not work on all matrices, especially singular or non-square matrices. Pivoting, or row exchanges, may be necessary to handle matrices with zeros on the diagonal, a process known as LU factorization with partial pivoting.</li>
    </ul>


<h1>6. Bisection Method</h1>
<p>The Bisection method is a straightforward and stable numerical method for computing the roots of a continuous function. It works especially fine when a function is continuous on a closed interval and the root is guaranteed to exist between two points in that interval. The method makes use of the so-called Intermediate Value Theorem that says: if a function changes the sign over an interval, then it has at least one root in that interval.</p>
<h2>Steps of the Bisection Method</h2>

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

<h1>Finding the Root of the Function</h1>
    <p>
        <div class="equation">
        Let's consider the function f(x) = x<sup>2</sup> - 4x + 10 and find the root in the interval [5, 6].
        </div>
    </p>  

<ol>
        <li><strong>Initial Points</strong>: a = 5, b = 6 since f(5) < 0 and f(6) > 0.</li>
        <li><strong>First Iteration</strong>:
            <ul>
                <li>Compute <i>c = (5 + 6) / 2 = 5.5</i>.</li>
                <li>Compute <i>f(5.5) = (5.5)² - 4(5.5) + 10 = 30.25 - 22 + 10 = 18.25</i>.</li>
                <li>Since <i>f(5) · f(5.5) < 0</i>, update <i>b = 5.5</i>.</li>
            </ul>
        </li>
        <li><b>Second Iteration</b>:
            <ul>
                <li>Compute <i>c = (5 + 5.5) / 2 = 5.25</i>.</li>
                <li>Find <i>f(5.25) = (5.25)² - 4(5.25) + 10 = 27.5625 - 21 = 6.5625</i>.</li>
                <li>Update <i>b = 5.25</i> (since <i>f(5) · f(5.25) < 0</i>).</li>
            </ul>
        </li>
        <li><b>Following Iterations</b>:
            <p>Continue iterations until the interval is small enough, thereby afetr 13 iterations the final root is 5.74164 .</p>
        </li>
    <h2>Advantages and Limitations</h2>


<b>Advantages :</b>
<ul>
        <li>The Bisection Method is certain to converge provided the initial interval has been chosen correctly.</li> 
        <li>It has a very simple formulation and hence easy to understand.</li>
        <li>It can be applied to any continuous function.</li>
</ul>

<b>Limitations</b>: 
<ul>
        <li>The method might be slow to converge, especially if the function has roots close to each other.</li>
        <li>It applies only to functions that change sign over the interval.</li>
        <li>The method needs initial guesses that bracket the root.</li>
</ul>

<p>Bisection Method is perhaps the most basic numerical method, but it is at the same time a foundation of other, usually more complex root finding methods.</p>


<h1>7. False Position Method</h1>
<p>
The False Position, is a numerical method for finding the roots of a function. It shares features of both the Bisection Method and the Secant Method. It uses two initial guesses, like the Bisection Method, to create an interval; however, as opposed to choosing the midpoint, it uses a linear interpolation in order to estimate the root. This often results in faster convergence than does the Bisection Method. <p>

<p>The method is based on the assumption that the root lies between two points a and b, where f(a) and f(b) have opposite signs. The formula for finding the root is derived from the secant line through the points ((a, f(a)) and ((b, f(b)):<p>
<div class="equation">
        x<sub>r</sub> = b -
        <frac>f(b)(a - b)</frac> /
        <frac>f(a) - f(b)</frac>
    </div>
    <p>where:</p>
    
<ul>
<li><i>x<sub>r</sub></i> is the estimated root.</li>
<li>Current interval endpoints, <i>a</i> and <i>b</i>.</li>
<li>Values of <i>f(a)</i> and <i>f(b)</i> at the current interval endpoints.</li>
</ul>

<h2>Steps of the False Position Method</h2>

<ol>
 <li><b>Choose Initial Points</b>:</li>
<p>Choose two starting points, <i>a</i> and <i>b</i>, such that <i>f(a) &cdot; f(b) &lt; 0</i>. This ensures that there is at least one root within the interval <i>[a, b]</i>.</p>
</li>
        
<li><b>Calculate the Root Estimate</b>:
<p>Use the False Position formula to find an approximate value of <i>x<sub>r</sub></i>:</p>
            <div class="equation">
                x<sub>r</sub> = b -
<frac>f(b)(a - b)</frac> /
                <frac>f(a) - f(b)</frac>
            </div>
</li>

<li><b>Evaluate the Function</b>:
<p>Find the value of function at <span>x<sub>r</sub>: f(x<sub>r</sub>)</span> </p>
</li>
       
<li><b>Interval Update</b>: 
            <p>Based on the sign of <span>f(x<sub>r</sub>)</span>, do an appropriate update to the interval:
<ul>
                <li>If <i>f(a) &cdot; f(x<sub>r</sub>) &lt; 0</i>, then the root lies in <i>[a, x<sub>r</sub>]</i>. Set <i>b = x<sub>r</sub></i>.</li>
                <li>If f(b) · f(xr) < 0, then the root lies in [xr, b]. Set a = xr.</li>
</ul>
</li>
            
<li><b>Repeat</b>:
<p>Repeat steps 2 through 4 until the absolute difference between successive estimates is less than a given tolerance <i>ε</i>, or until the function value at the root estimate is sufficiently close to zero.</p>
</li>
</ol>

<h2>Example</h2>

<p>Now let's find the root for the function <span>f(x) = x<sup>2</sup> - 4x + 10</span>.</p>
<ol>
    <li><b>Initial Points</b>: Let <i>a = 5</i> and <i>b = 6</i> (since <i>f(5) < 0</i> and <i>f(6) > 0</i>).</li>
    <li><b>First Iteration</b>:
        <ul>
            <li>Compute: <i>f(a) = f(5) = (5)<sup>2</sup> - 4(5) + 10 = 25 - 20 + 10 = 15</i>.</li>
            <li>Compute: <i>f(b) = f(6) = (6)<sup>2</sup> - 4(6) + 10 = 36 - 24 + 10 = 22</i>.</li>
            <li>Calculate the estimate for root,
                <div class="equation">
                    x<sub>r</sub> = 6 - 
                    <frac>22(5 - 6)</frac> /
                    <frac>15 - 22</frac> = 6 - 
                    <frac>-22}{-7} = 6 + 3.14 = 9.14
                </div>
            </li>
        </ul>
    </li>
    <li><b>Function Evaluation</b>:
        <p>Calculate <i>f(9.14) = (9.14)<sup>2</sup> - 4(9.14) + 10 = 83.54 - 36.56 + 10 = 56.98</i>.</p>
    </li>
    <li><b>Interval Update</b>:
        <p>Since <i>f(5) · f(9.14) > 0</i>, we set <i>a = 9.14</i>.</p>
    </li>
    <li><b>Repeat</b>:
        <p>Take <i>a = 9.14</i> and <i>b = 6</i> for the next iteration and repeat the process until the desired accuracy is achieved.</p>
    </li>
</ol>


<h2>Advantages and Limitations</h2>
<ol>
<li><b>Advantages</b:</li>
            <ul>
                <li>The False Position Method has much faster convergence than the Bisection Method because it employs a better approximation of the root.
                <li>It is simple to implement and does not require derivative information.</li>
            </ul>
        
<li><b>Limitations</b>: </li>
            <ul>
                <li>It can be slower than other methods, such as Newton's method, when applied to functions that are not well-behaved.</li>
                <li>If the function is not sufficiently continuous or if the initial guesses are not chosen appropriately, convergence may be slow or may not occur.</li>
            </ul>
</ol>
The false position method represents a very useful tool in root finding, especially for continuous functions whose function behavior could be quite easy to analyze.

<h1>8. Secant Method</h1>
<p>The Secant Method is a technique to find a root of a function numerically. Unlike the Bisection Method, which takes two initial points by creating intervals, the Secant Method approximates the root by taking two initial guesses and then creating a secant line between them. This is an iterative technique that, under appropriate conditions, converges faster than the Bisection Method.</p>

<h2>How the Secant Method Works</h2>
    <p>The Secant Method uses the formula below and iteratively converges to a root:</p>
    <div class="equation">
        x<sub>n+1</sub> = x<sub>n</sub> - f(x<sub>n</sub>) &cdot; 
        <frac>x<sub>n</sub> - x<sub>n-1</sub></frac> / 
        <frac>f(x<sub>n</sub>) - f(x<sub>n-1</sub>)</frac>
</div>
    <p>where:</p>
    <ul>
        <li><i>x<sub>n</sub></i> and <i>x<sub>n-1</sub></i> are the current and previous approximations of the root, respectively.</li>
        <li><i>f(x)</i> is the function for which we want to find the root.</li>
    </ul>

<h2>Steps of the Secant Method</h2>
    <ol>
<li><b>Choose Initial Guesses</b>: 
            <p>First Pick two initial guesses <i>x<sub>0</sub></i> and <i>x<sub>1</sub></i> such that <i>f(x<sub>0</sub>)</i> and <i>f(x<sub>1</sub>)</i> are not equal to zero.</p>
        </li>
        <li><b>Iterate</b>:
<p>Apply the Secant Method formula to find the next approximation \(x_2\): </p>
            <div class="equation">
                x<sub>2</sub> = x<sub>1</sub> - f(x<sub>1</sub>) &cdot;
<div class="d-flex justify-content-center">
            <frac>x<sub>1</sub> - x<sub>0</sub></frac> /
                <frac>f(x<sub>1</sub>) - f(x<sub>0</sub>)</frac>
            </div>
<p>Refresh previous values: make <i>x<sub>0</sub> = x<sub>1</sub></i> and <i>x<sub>1</sub> = x<sub>2</sub></i>.</p>
        </li>
        <li><b>Convergence Check</b>:</
Iterate repeatedly until the absolute difference between successive approximations is less than a given tolerance :
            <div class="equation">|x<sub>n+1</sub> - x<sub>n</sub>| < ε</div>
            <p>Alternatively, terminate if Notice that it is not necessary for a zero of the function to exist at the initial point x0.
</li>
    </ol>

<h2>Example</h2>
<p>Consider the function <i>f(x) = x² - 4x + 10</i>. We want to find the root.</p>
<ol>
    <li><b>Initial Guesses</b>: Let <i>x<sub>0</sub> = 4</i> and <i>x<sub>1</sub> = 2</i>.</li>
    <li><b>First Iteration</b>:
        <ul>
            <li>Calculate <i>f(x<sub>0</sub>) = f(4) = (4)² - 4(4) + 10 = 16 - 16 + 10 = 10</i>.</li>
            <li>Calculate <i>f(x<sub>1</sub>) = f(2) = (2)² - 4(2) + 10 = 4 - 8 + 10 = 6</i>.</li>
            <li>Employ the Secant Method formula:
                <div class="equation">
                    x<sub>2</sub> = 2 - 6 &cdot; 
                    <frac>2 - 4</frac> /
                    <frac>6 - 10</frac> = 2 - 6 &cdot; 0.5 = 2 - 3 = -1
                </div>
            </li>
        </ul>
    </li>
    <li><b>Second Iteration</b>:
        <ul>
            <li>Iteration: x<sub>0</sub> = 2, x<sub>1</sub> = -1</li>
            <li>Calculate <i>f(-1) = (-1)² - 4(-1) + 10 = 1 + 4 + 10 = 15</i>.</li>
            <li>Again using the formula:
                <div class="equation">
                    x<sub>3</sub> = -1 - 15 &cdot; 
                    <frac>-1 - 2</frac> /
                    <frac>15 - 6</frac> = -1 - 15 &cdot; (-1) / 9 = -1 + 2.5 = 1.5
                </div>
            </li>
        </ul>
    </li>
    <li><b>Continue Iterating</b>:
        <p>Repeat this process until the desired accuracy is achieved.</p>
    </li>
</ol>

<h2>Advantages and Limitations</h2>
    <ol>
        <li><b>Advantages</b>: </li>
            <ul>
                <li>The Secant Method is generally faster compared to the Bisection Method.</li>
                <li>It does not require that the function be evaluated at the midpoint; this can be computationally sparing in some instances.</li>
            </ul>
        
<li><b>Limitations</b>: </li>
        <ul>
                <li>The method may not converge if the initial guesses are too far from the actual root.</li>
                <li>It relies on the function values at the initial guesses to be different, or else the method will fail.</li>
                <li>The Secant Method is not as surefire as methods employing derivatives such as Newton's method for functions that are ill-behaved.</li>
        </ul>
       
</ol>

<p>The Secant Method is really powerful for finding roots of functions, and particularly useful in those cases when one does not have any derivative information. For this reason, it serves as a kind of bridge between more simple methods, such as the Bisection method, and more sophisticated techniques.</p>

<h1>9. Newton-Raphson Method</h1>
<p>The Newton-Raphson Method is perhaps the most effective numerical method for finding approximations to the roots or zeros of a real-valued function. In its iterations, it utilizes the tangent concept in order to converge to a root. It sees great application for functions that are differentiable and whose derivative can be calculated out easily.</p>

<p>The Newton-Raphson formula follows directly from the principle of linear approximation. Given a function <i>f(x)</i> and its derivative <i>f′(x)</i>, with an initial approximation <i>x<sub>0</sub></i> to the root, the formula is expressed as:</p>

<div class="equation">
    x<sub>n+1</sub> = x<sub>n</sub> - 
    <frac>f(x<sub>n</sub>)</frac> /
    <frac>f'(x<sub>n</sub>)</frac>
</div>

</div>
    <p>where:</p>
        <ul>
        <li><i>x<sub>n</sub></i> is the current approximation.</li>
        <li><i>f(x<sub>n</sub>)</i> is the value of the function at <i>x<sub>n</sub></i>.</li>
        <li><i>f′(x<sub>n</sub>)</i> is the value of the derivative at <i>x<sub>n</sub></i>.</li>
        </ul>

<h2>Steps of the Newton-Raphson Method</h2>
<ol>
        <li><b>Choose an Initial Guess</b>:
         <p>The first step is to select an initial guess \(x_0\) that is reasonably close to the root.</p>
        </li>
        <li><b>Evaluate the Function and Its Derivative</b>:
            <p>Calculate <i>f(x<sub>0</sub>)</i> and <i>f'(x<sub>0</sub>)</i>.</p>
        </li>
        <li><b>Update the Estimate</b>:
        <p>By the Newton-Raphson formula, find the next approximation to the root, <i>x<sub>1</sub></i>:</p>
            <div class="equation">
                x<sub>1</sub> = x<sub>0</sub> -
<div class="d-flex flex-justify-center">
                <frac>f(x<sub>0</sub>)</frac> /
                <frac>f'(x<sub>0</sub>)</frac>
            </div>
        </li>
        <li><b>Check for Convergence</b>:
Check if the approximation converges by checking that the absolute difference of successive approximations is smaller than a given tolerance ε: 
            <div class="equation">
                |x<sub>n+1</sub> - x<sub>n</sub>| &lt; ε
OR check if <i>|f(x<sub>n+1</sub>)| < ε</i>.</p>
        </li>
        <li><b>Iterate</b>:
<p>If convergence criteria are not met, set <i>x<sub>0</sub> = x<sub>1</sub></i> and repeat steps 2 to 4.</p>
        </li>
    </ol>

<h2>Example</h2>
<p>Consider the function <i>f(x) = x² - 3x + 2</i>. We want to find the root.</p>
<ol>
    <li><b>Choose Initial Guess</b>: Let <i>x<sub>0</sub> = 0</i>.</li>
    <li><b>Evaluate the Function and Its Derivative</b>:
        <ul>
            <li><i>f(0) = 0² - 3(0) + 2 = 2</i></li>
            <li><i>f′(0) = 2(0) - 3 = -3</i></li>
        </ul>
    </li>
    <li><b>Update the Estimate</b>:
        <p>Compute <i>x<sub>1</sub></i>:</p>
        <div class="equation">
            x<sub>1</sub> = 0 - 
            <frac>2</frac> /
            <frac>-3</frac> = 0 + 0.66667 = 0.66667
        </div>
    </li>
    <li><b>Check for Convergence</b>:
        <ul>
            <li>Compute <i>f(0.66667) = (0.66667)² - 3(0.66667) + 2 ≈ 0.4444</i></li>
            <li>Compute <i>f′(0.66667) = 2(0.66667) - 3 ≈ -1.66667</i></li>
            <li>Compute <div class="equation">
                x<sub>2</sub> = 0.66667 - 
                <frac>0.4444</frac> /
                <frac>-1.66667</frac> ≈ 0.66667 + 0.26667 = 0.93334
            </div></li>
        </ul>
    </li>
    <li><b>Repeat</b>:
        <p>Repeat this process until the desired accuracy is reached.</p>
    </li>
</ol>

<h2>Advantages and Limitations</h2>
        <ol>
                <li><b>Advantages</b>: </li>
            <ul>
                <li>The Newton-Raphson Method converges very fast for an initial guess close enough to the exact root. Fewer numbers of iterations are required as compared to other methods, such as Bisection or Secant.</li>
                <li>It can be employed in finding multiple roots, and it can be applied to a wide range of functions. </li>
            </ul>
        
<li><b>Limitations:</b></li>
        <ul>
                <li>If the initial guess is not sufficiently close to the root, or if the function has discontinuities there, or is not differentiable there, then the method might fail to converge.</li>
        <li>The method may be unstable if the derivative f′(xn) is zero or near zero; it could also result in division by zero.</li>
        <li>It may be converge to a local extrema rather than a root, especially for non-monotonic functions.</li>
            </ul>
</ol>
<p>The Newton-Raphson Method has become a significant avenue for numerical equation solutions, finding wide applications in several areas, including engineering, physics, and computer science.
</p>

<h1>10. Runge-Kutta Method (4th Order)</h1>
    <p>The Runge-Kutta method or RK mehtod is a popular iterative technique for solving ordinary differential equations (ODEs) of the form:</p>
    <div class="equation">dy/dx = f(x, y)</div>
    <p>where:</p>
    <ul>
        <li><b>f(x, y)</b> is a function of <i>x</i> and <i>y</i>.</li>
        <li><b>y</b> is the dependent variable we aim to approximate over the interval <i>[x<sub>0</sub>, x<sub>n</sub>]</i>.</li>
    </ul>
    <p>The 4th Order Runge-Kutta method provides a balance between accuracy and computational efficiency, making it one of the most widely used methods for solving ODEs.</p>
    <p>Here three equations have been set as default to apply the RK method and also set the range of the value as well as number of steps to get a good look how the values of x and y are changing in each step.</p>
    <p>The functions are :</p>
<ol>
        <li>dy/dx = x - y</li>
        <li>dy/dx = sin(x)</li>
        <li>dy/dx = cos(x)</li>
</ol>

<h2>Runge-Kutta Method Algorithm</h2>
    <p>To approximate <b>y</b> over the interval <b>[x<sub>0</sub>, x<sub>n</sub>]</b>:</p>
    <ol>
        <li><b>Initialization</b>: Start with initial conditions <i>x<sub>0</sub></i> and <i>y<sub>0</sub></i>.</li>
        <li><b>Calculate Intermediate Slopes</b>:
            <ul>
                <li>Compute <i>k<sub>1</sub></i>: <span class="equation">k<sub>1</sub> = h * f(x<sub>0</sub>, y<sub>0</sub>)</span></li>
                <li>Compute <i>k<sub>2</sub></i>: <span class="equation">k<sub>2</sub> = h * f(x<sub>0</sub> + h/2, y<sub>0</sub> + k<sub>1</sub>/2)</span></li>
                <li>Compute <i>k<sub>3</sub></i>: <span class="equation">k<sub>3</sub> = h * f(x<sub>0</sub> + h/2, y<sub>0</sub> + k<sub>2</sub>/2)</span></li>
                <li>Compute <i>k<sub>4</sub></i>: <span class="equation">k<sub>4</sub> = h * f(x<sub>0</sub> + h, y<sub>0</sub> + k<sub>3</sub>)</span></li>
            </ul>
        </li>
        <li><b>Update <i>y</i></b>: Calculate <span class="equation">y = y<sub>0</sub> + (1/6)(k<sub>1</sub> + 2k<sub>2</sub> + 2k<sub>3</sub> + k<sub>4</sub>)</span></li>
        <li><b>Repeat</b>: Update <i>x<sub>0</sub></i> by adding the step size <b>h</b> and set <i>y<sub>0</sub> = y</i>. Repeat steps 2-3 until the desired endpoint <i>x<sub>n</sub></i> is reached.</li>
    </ol>



<h2>Advantages of the Runge-Kutta Method</h2>
    <ul>
        <li>High accuracy compared to simpler methods like Euler's method.</li>
        <li>4th-order Runge-Kutta provides a balance of efficiency and computational cost.</li>
        <li>Widely applicable and does not require higher derivatives of the function.</li>
    </ul>

<h2>Disadvantages of the Runge-Kutta Method</h2>
    <ul>
        <li>More computationally expensive than first-order methods.</li>
        <li>Requires smaller step sizes for stiff equations, leading to more iterations.</li>
        <li>Not memory efficient for large systems due to intermediate slope calculations.</li>
    </ul>
</body>

<h1>11. Matrix Inversion</h1>
Matrix inversion is among the basic operations in linear algebra and is defined as the calculation of a matrix $A^{-1}$ , known as the inverse of matrix A, such that its multiplication with A results in the identity matrix I. The identity matrix is a square matrix with 1s on the diagonal and zeroes elsewhere.


Definition
Given a square matrix A of order n, its inverse $A^{-1}$ fulfills the following requirement: $AA^{-1} = A^{-1} A = I$ where I is the n × n identity matrix. 

<h3>Conditions for Invertibility</h3>
Not all matrices possess inverses. A square matrix A is said to be invertible (or non-singular) if:
<ol>
<li><b>Determinant Condition</b>: The determinant of A must be non-zero thus det(A) ≠ 0</li>
<li><b>Square Matrix</b>: The matrix should be square in nature, i.e., it must have the same number of rows as well as columns.
</ol>
<p"When the value of determinant is zero, then the matrix is said to be singular and its inverse does not exist.

<p><h2>Gauss-Jordan Elimination:</h2></p>
<p>This method involves augmenting the matrix <i>A</i> with the identity matrix <i>I</i> and applying row operations to transform <i>A</i> into <i>I</i>. The augmented part will then become <i>A<sup>-1</sup></i>.</p>

<h2>Example</h2>
    <p>Considering the following system for sample test:
<div class="equation">
        <pre>
        10a + 2b  - c   + 3d  + 4e = 30
        3a  + 12b + 4c  - d   + 2e = 20
        2a  + b   + 11c - 2d  + 3e = 10
        a   + 2b  - 3c  + 10d + e  = 15
        4a  - b   + 3c  + 2d  + 9e = 25
       </pre>
</div>
<p>Using the above system first forming a 5 X 5 matrix and then using the Gauss Jordan Elimination to solve detemine the inverse matrix</p>
<h2>Limitations:</h2>
<ul>
<li><b>Computational Complexity</b>: The inverse of large-size matrices involves heavy computational complexity and can lead to numerical instability.</li>
<li><b>Singular Matrices</b>: If a matrix is singular, then it cannot be used in those types of calculations which require its inverse.</li></ul>    


  
