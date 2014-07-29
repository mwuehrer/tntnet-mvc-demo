<?php
session_start();

if (!isset($_SESSION['cnt']))
{
    $_SESSION['cnt'] = 0;
}
$_SESSION['cnt'] ++;
?>
<!DOCTYPE HTML>
<html>
    <head>
        <meta charset="UTF-8">
        <meta name="description" content="TNTNET MVC Demo">
        <link rel="stylesheet" type="text/css" href="style.css">
        <link rel="icon" type="image/x-icon" href="favicon.ico">
    </head>
    <body>
        <header>
            <h1><a href="index.php">PHP Reference Demo</a></h1>
        </header>
        <main>
            
<h2>Index-Content</h2>

<div>
    You requested the page <?=$_SESSION['cnt']?>-times.<br>
</div>

<div>
This page is written in PHP, but it also has a sister-page (written in c++ by tntnet), which has the same features. <br>
Both pages were written, to compare the speed of tntnet against php.
</div>

<h3>You have the following possibilities:</h3>

<ul>
<li><a href="fibonacci.php">Fibonacci</a></li>
<li><a href="sort_int.php">Sort Int</a></li>
<li><a href="js/index.html">Loads of JS-files</a></li>
<li><a href="static_resource.htm">Static Resource</a></li>
<li><a href="tux.svg">Tux</a></li>
</ul>

<h3>Or you go to the sister-page:</h3>

<div>
<a href="/">Page in C++</a>
</div>

        </main>
        <footer>
            under GPLv3
        </footer>
    </body>
</html>

