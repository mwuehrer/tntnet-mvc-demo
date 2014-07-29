<?php

function fibonacci($num) {
    if ($num == 0) {
        return 0;
    }

    if ($num == 1) {
        return 1;
    }
    return fibonacci($num - 1) + fibonacci($num - 2);
}

function calc($param) {
    if(!empty($param)) {
        return fibonacci($param);
    } else {
        return NULL;
    }
}
?>
