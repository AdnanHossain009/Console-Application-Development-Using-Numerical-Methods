# Console-Application-Development-Using-Numerical-Methods
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gaussian Elimination Method</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; }
        h1 { color: #333; }
        h2 { color: #555; }
<style>
        .equation { font-style: italic; margin: 10px 0; }
        ul { margin-top: 0; }
    </style>
</head>
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
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Gauss-Jordan Elimination Method</title>
    <style>
        body { font-family: Arial, sans-serif; line-height: 1.6; }
        h1 { color: #333; }
        h2 { color: #555; }
<style>
        .equation { font-style: italic; margin: 10px 0; }
        ul { margin-top: 0; }
    </style></head>
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
