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
            
<h2>Sort Int</h2>

<div>
Press the Button, to sort n-Elements:
<form method='get'>
<input type="submit" name="arg_num" value="10000">
<input type="submit" name="arg_num" value="100000">
<input type="submit" name="arg_num" value="1000000">
<input type="submit" name="arg_num" value="5000000">
</form>
</div>

<?php
    $values = array();
    if(empty($_GET["arg_num"])) {
        $_GET["arg_num"] = 10000;
    }
    $time_start = microtime(true);

    switch ($_GET["arg_num"]) {
        case 10000:
            include 'sort_values_10000.inc.php';
            $values = $INT_VALUES_10000;
            break;
        case 100000:
            include 'sort_values_100000.inc.php';
            $values = $INT_VALUES_100000;
            break;
        case 1000000:
            include 'sort_values_1000000.inc.php';
            $values = $INT_VALUES_1000000;
            break;
        case 5000000:
            include 'sort_values_5000000.inc.php';
            $values = $INT_VALUES_5000000;
            break;
        default:
            throw new Exception("Given Argument arg_num='" . $_GET["arg_num"] . "' is out of range.");
    }
    sort($values);
    $time = microtime(true) - $time_start;
?>

<h3>Sorted <?=$_GET["arg_num"]?> Integers: (calculated in <?=($time*1000)?> milliseconds)</h3>

<div>
<?foreach($values as $value):?>
<?=$value?>,
<?endforeach;?>]
</div>

        </main>
        <footer>
            under GPLv3
        </footer>
    </body>
</html>
