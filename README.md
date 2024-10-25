# Console-Application-Development-Using-Numerical-Methods

<body>
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
    <span>a<sub>nn</sub>x<sub>n</sub> = b'<sub>n</sub></span>
    <span>a<sub>(n-1)(n-1)</sub>x<sub>(n-1)</sub> + a<sub>(n-1)n</sub>x<sub>n</sub> = b'<sub>(n-1)</sub></span>
    <span>&#8942;</span> <!-- Vertical dots (ellipsis) -->
</div>
a<sub>11</sub> x<sub>1</sub> + a<sub>12</sub> x<sub>2</sub> +. + a<sub>1n</sub> x<sub>n</sub> = b'<sub>1</sub>
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
    <p><b>2. Back Substitution:</b> Solve for <i>z</i> from the last equation, then by substitution solve for <i>y</i>, and finally <i>x</i>.</p>

<h2>Advantages and Limitations</h2>

<ul>
    <li><b>Advantages</b>: Gaussian elimination is a systematic method that works for any invertible matrix.</li>
    <li><b>Limitation</b>: The method can be computationally expensive for large matrices. Gaussian elimination may also be prone to numerical instability, in particular if the magnitudes of the pivot elements are close to zero.</li>
</ul></body>

<h1>4. Gauss-Jordan Elimination Method</h1>
Gauss-Jordan Elimination is an extended form of Gaussian elimination for the solution of systems of linear equations. sSo after eliminating the variables above the pivot in the "Gauss-Jordan elimination" we eliminate the variables below each pivot to create a thoroughly simplified matrix from which one can read directly from the matrix.

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
<p><b>1. Forward Elimination:</b> Select the pivot for the first row and, if it isn't already 1, then set the row divided by its entry equal to 1, then use it to eliminate the entries below the pivot. Repeat for each pivot until the matrix is in row echelon form.
<p><b>2. Backward Elimination:</b> For each pivot, make the entries above zero and obtain a reduced row echelon form in which variables can be read directly.</p>

<h2>Pros and Cons</h2>
<ul>
<li><b>Advantages</b>: Gauss-Jordan elimination reduces a matrix to its most simplified form, from which the solutions can be directly read without any further substitution. This makes it quicker and more systematic for solving systems compared to Gauss' elimination methods.
</ul>


<h1>11. Matrix Inversion</h1>
<p>
Matrix inversion is among the basic operations in linear algebra and is defined as the calculation of a matrix, $A^{-1}, known as the inverse of matrix A, such that its multiplication with A results in the identity matrix I. The identity matrix is a square matrix with 1s on the diagonal and zeroes elsewhere.
</p>

<h3>Conditions for Invertibility</h3>
Not all matrices possess inverses. A square matrix A is said to be invertible (or non-singular) if:
<ol>
<li><b></b>Determinant Condition</b>: The determinant of A muzt be non-zero thus det(A) ≠ 0</li>
<li><b>Square Matrix</b>: The matrix should be square in nature, i.e., it must have the same number of rows as well as columns.
</ol>
<p"When the value of determinant is zero, then the matrix is said to be singular and its inverse does not exist.

<p>Gauss-Jordan Elimination:</p>
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
Limitations
<ul>
<li><b>Computational Complexity</b>: The inverse of large-size matrices involves heavy computational complexity and can lead to numerical instability.</li>
<li><b>Singular Matrices</b>: If a matrix is singular, then it cannot be used in those types of calculations which require its inverse.</li>
<ul>

    
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


<h1>7. False Position Method</h1>
The False Position, is a numerical method for finding the roots of a function. It shares features of both the Bisection Method and the Secant Method. It uses two initial guesses, like the Bisection Method, to create an interval; however, as opposed to choosing the midpoint, it uses a linear interpolation in order to estimate the root. This often results in faster convergence than does the Bisection Method. 

The method is based on the assumption that the root lies between two points a and b, where f(a) and f(b) have opposite signs. The formula for finding the root is derived from the secant line through the points ((a, f(a)) and ((b, f(b)):
<div class="equation">
        x<sub>r</sub> = b -
        <frac>f(b)(a - b)</frac> /
        <frac>f(a) - f(b)</frac>
    </div>
    <p>where:</p>
    <ul>
        <li><i>x<sub>r</sub></i> is the estimated root.</li>
• Current interval endpoints, <i>a</i> and <i>b</i>.
 • Values of <i>f(a)</i> and <i>f(b)</i> at the current interval endpoints.
 </ul>
<h2>Steps of the False Position Method</h2>

<ol>
 • <b>Choose Initial Points</b>:
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
<p>Find the value of function at \(x_r\): \(f(x_r)\) </p>
        </li>
        <li><b>Interval Update</b>: 
            <p>Based on the sign of \(f(x_r)\), do an appropriate update to the interval:
<ul>
                <li>If <i>f(a) &cdot; f(x<sub>r</sub>) &lt; 0</i>, then the root lies in <i>[a, x<sub>r</sub>]</i>. Set <i>b = x<sub>r</sub></i>.</li>
• If f(b) · f(xr) < 0, then the root lies in [xr, b]. Set a = xr.
                </ul>
            </li>
            <li><b>Repeat</b>:
<p>Repeat steps 2 through 4 until the absolute difference between successive estimates is less than a given tolerance <i>ε</i>, or until the function value at the root estimate is sufficiently close to zero.</p>
        </li>
    </ol>
    <h2>Example</h2>

Now let's find the root for the function f(x) = x² - 4.
    <ol>
        <li><b>Initial Points</b>: Let a = 0 and b = 5 (since f(0) < 0 and f(5) > 0).</li>
        <li><b>First Iteration</b>:
            <ul>
<li>Compute: <i>f(a) = f(0) = 0² - 4 = -4</i>.</li>
 <li>Compute: <i>f(b) = f(5) = 5² - 4 = 21</i>.</li>
<li>Calculate the estimate for root,
                    <div class="equation">
                        x<sub>r</sub>=5-
<frac>21(0 - 5)</frac> /
                        <frac>-4 - 21</frac> = 5 -
<frac>-105>-25=5-4.2=0.8</frac>
                    </div>
                </li>
</ul>
        </li>
        <li><b>Function Evaluation</b>:
            <p>Calculate <i>f(0.8) = (0.8)² - 4 = -3.36</i>.</p>
        </li>
        <li><b>Interval Update</b>:
Since <i>f(0) &cdot; f(0.8) &lt; 0</i>, we set <i>b = 0.8</i>.</p>
        </li>
        <li><b>Repeat</b>:
<p>Take <i>a = 0</i> and <i>b = 0.8</i> for the next iteration and repeat the process until the desired accuracy is achieved.</p>
        </li>
    </ol>
<h2>Advantages and Limitations</h2>
    <ul>
        <li><b>Advantages</b}: 
            <ul>
                <li>The False Position Method has much faster convergence than the Bisection Method because it employs a better approximation of the root.
<li>It is simple to implement and does not require derivative information.</li>
            </ul>
        </li>
        <li><b>Limitations</b>: 
            <ul>
• It can be slower than other methods, such as Newton's method, when applied to functions that are not well-behaved.
<li>If the function is not sufficiently continuous or if the initial guesses are not chosen appropriately, convergence may be slow or may not occur.</li>
            </ul>
        </li>
    </ul>

The false position method represents a very useful tool in root finding, especially for continuous functions whose function behavior could be quite easy to analyze.
<!DOCTYPE html>
<html lang="en">
<body>
    <h1>Secant Method</h1>
The Secant Method is a technique to find a root of a function numerically. Unlike the Bisection Method, which takes two initial points by creating intervals, the Secant Method approximates the root by taking two initial guesses and then creating a secant line between them. This is an iterative technique that, under appropriate conditions, converges faster than the Bisection Method.

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
            <p>Pick two initial guesses <i>x<sub>0</sub></i> and <i>x<sub>1</sub></i> such that <i>f(x<sub>0</sub>)</i> and <i>f(x<sub>1</sub>)</i> are not equal to zero.</p>
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
    <p>Consider the function <i>f(x) = x² - 4</i>. We want to find the root.</p>
    <ol>
        <li><b>Initial Guesses</b>: Let <i>x<sub>0</sub> = 1</i> and <i>x<sub>1</sub> = 3</i>.</li>
        <li><b>First Iteration</b>:
<ul>
                <li>Calculate <i>f(x<sub>0</sub>) = f(1) = 1² - 4 = -3</i>.</li>
                <li>Calculate <i>f(x<sub>1</sub>) = f(3) = 3² - 4 = 5</i>.</li>
<li>Employ the Secant Method formula:
                    <div class="equation">
x<sub>2</sub> = 3 - 5 &cdot; 
                        <frac>3 - 1</frac> /
<frac>5 - (-3)</frac> = 3 - 5 ⋅ 0.25 = 1.75
                    </div>
</li>
            </ul>
        </li>
        <li><b>Second Iteration</b>:
            <ul>
<li>Iteration: x0=3, x1=1.75
             </li>
                <li>Calculate f(1.75) =(1.75)2−4≈−1.9375
             </li>
                <li>Again using the formula:
<div class="equation">
                x_{3} = 1.75 - (-1.9375) ·
<frac>1.75 - 3</frac> / 
                         <frac>-1.9375 - 5</frac> ≈ 1.75 + 0.64 ≈ 2.39
</div>
                </li>
            </ul>
        </li>
        <li><b>Continue Iterating</b>:
<p>Repeat this process until desired accuracy is achieved.</p>
        </li>
    </ol>
<h2>Advantages and Limitations</h2>
    <ul>
        <li><b>Advantages</b>: 
            <ul>
                <li>The Secant Method is generally faster compared to the Bisection Method.</li>
• It does not require that the function be evaluated at the midpoint; this can be computationally sparing in some instances.
            </ul>
        </li>
        <li><b>Limitations</b>:
<ul>
                <li>The method may not converge if the initial guesses are too far from the actual root.</li>
• It relies on the function values at the initial guesses to be different, or else the method will fail.
• The Secant Method is not as surefire as methods employing derivatives such as Newton's method for functions that are ill-behaved.
</ul>
        </li>
    </ul>

    The Secant Method is really powerful for finding roots of functions, and particularly useful in those cases when one does not have any derivative information. For this reason, it serves as a kind of bridge between more simple methods, such as the Bisection method, and more sophisticated techniques.
