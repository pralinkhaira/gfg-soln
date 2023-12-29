<h2><a href="https://www.geeksforgeeks.org/problems/check-if-a-string-is-repetition-of-its-substring-of-k-length3302/1">Check if a string is repetition of its substring of k-length</a></h2><h3>Difficulty Level : Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-family: arial, helvetica, sans-serif;"><span style="font-size: 18px;">Given a string <strong>s</strong>, check if it is possible to convert it into a string that is the <strong>repetition </strong>of a substring of <strong>length k</strong>. Conversion has to be done by following the steps mentioned below only once:</span></span></p>
<ol>
<li><span style="font-family: arial, helvetica, sans-serif;"><span style="font-size: 18px;">Select two indices&nbsp;<strong>i&nbsp;</strong>and&nbsp;<strong>j&nbsp;</strong></span></span>(<strong style="font-family: arial, helvetica, sans-serif; font-size: 18px;">zero-based indexing, i </strong><span style="font-family: arial, helvetica, sans-serif; font-size: 18px;">could be equal to </span><strong style="font-family: arial, helvetica, sans-serif; font-size: 18px;">j</strong><span style="font-family: arial, helvetica, sans-serif; font-size: 18px;">), such that <strong>i</strong> and <strong>j </strong>are divisible by <strong>k</strong>.</span></li>
<li><span style="font-family: arial, helvetica, sans-serif; font-size: 18px;">Select substrings of length <strong>k</strong> starting from indices <strong>i</strong> and <strong>j.</strong></span></li>
<li><span style="font-family: arial, helvetica, sans-serif; font-size: 18px;">Replace substring starting at index <strong>i</strong> with substring starting at index <strong>j </strong>within the string.</span></li>
</ol>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
N = 4<br>K = 2<br>S = "bdac"
<strong>Output:</strong> 1
<strong>Explanation</strong>: We can replace either
"bd" with "ac" or "ac" with "bd"
</span></pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input</strong>: 
N = 5<br>K = 2<br>S = "abcde"
<strong>Output:</strong> 0
<strong>Explanation</strong>: Since <strong>n</strong> % <strong>k</strong> != 0, it's not 
possible to convert <strong>s</strong> into a string which
is a concatanation of a substring with 
length <strong>k</strong>.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>kSubstrConcat()&nbsp;</strong>which takes a string <strong>s</strong>, its length <strong>n </strong>and an integer <strong>k </strong>as inputs and return <strong>1</strong> if convertion of the given string is possible, else <strong>0</strong>.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(n).<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(n).</span></p>
<p><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;"><strong>Constraints:</strong></span></span><br><span style="font-size: 18px;"><span style="font-family: arial,helvetica,sans-serif;">2 &lt;= k &lt; n &lt;= 10<sup>5</sup></span></span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Map</code>&nbsp;<code>Data Structures</code>&nbsp;