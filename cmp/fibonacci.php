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
            
<h2>Fibonacci</h2>

<?php
    $time_start = microtime(true);
    include 'fibonacci_func.inc.php';
    $result = calc($_GET["arg_value"]);

    $time = microtime(true) - $time_start;
?>

<?if($result != NULL):?>
Fibonacci-number of <?=$_GET["arg_value"]?> is: "<?=$result?>" (calculated in <?=($time)*1000?> milliseconds)
<?endif;?>

<form>
    <input type="number" name="arg_value" 
    <?if(empty($_GET["arg_value"])):?>
    value="10"
    <?else:?>
    value="<?=$_GET["arg_value"]?>"
    <?endif;?>
    > <br>
    <input type="submit" name="arg_calc" value="calculate">
</form>

        </main>
        <footer>
            under GPLv3
        </footer>
    </body>
</html>
