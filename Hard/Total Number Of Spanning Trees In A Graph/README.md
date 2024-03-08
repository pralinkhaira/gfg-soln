<h2><a href="https://www.geeksforgeeks.org/problems/total-number-of-spanning-trees-in-a-graph/1?page=10&difficulty=Hard&sortBy=submissions">Total Number Of Spanning Trees In A Graph</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a <strong>connected undirected graph</strong>&nbsp;of <strong>N</strong>&nbsp;</span><span style="font-size: 18px;">vertices</span><span style="font-size: 18px;">&nbsp;and </span><strong style="font-size: 18px;">M</strong><span style="font-size: 18px;">&nbsp;</span><span style="font-size: 18px;">edges</span><span style="font-size: 18px;">. The task is the find the total number of spanning trees possible in the graph.</span></p>
<p><span style="font-size: 18px;"><br><strong>Note:&nbsp;</strong>A&nbsp;<strong>spanning tree</strong>&nbsp;is a subset of Graph G, which has all the vertices covered with the minimum possible number of edges. Hence, a&nbsp;<strong>spanning tree</strong>&nbsp;does not have cycles and it cannot be disconnected. By this definition, we can draw a conclusion that every connected and undirected Graph G has at least one&nbsp;<strong>spanning tree.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
<code>N = 6, M = 5
graph = {{0, 3}
         {0, 1}
         {1, 2}.
         {1, 5},
         {3, 4}}</code> <strong>Output: </strong>1 <strong>Explanation:</strong> Only one spanning tree is possible,i.e. the graph itself. {{0, 1}, &nbsp;{0, 3}, &nbsp;{1, 2}, &nbsp;{1, 5}, &nbsp;{3, 4}} </span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>countSpanningTrees</strong><strong>()</strong>&nbsp;which takes two integers&nbsp;<strong>N</strong>&nbsp;and&nbsp;<strong>M</strong>&nbsp;and a 2D matrix denoting the connected edges and returns an integers as output.</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N<sup>4</sup>)<br><strong>Expected Auxiliary Space:</strong> O(N<sup>2</sup>)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 &lt;= N &lt;= 10<br>N - 1 &lt;= M&nbsp;&lt;= N *(N - 1) / 2<br>0 &lt;= graph[i][0], graph[i][1] &lt;= N - 1</span></p></div>