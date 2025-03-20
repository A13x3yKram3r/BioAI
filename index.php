<?php
if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    if (isset($_GET['data'])) {
        $data = $_GET['data'];  // Получаем строку с данными от Arduino
        file_put_contents("sensors.txt", $data . "\n", FILE_APPEND);
    }
}

if ($_SERVER['REQUEST_METHOD'] === 'GET') {
    if (isset($_GET['get_sensors'])) {
        if (file_exists('sensors.txt')) {
            $data = file_get_contents('sensors.txt');
            echo $data;
        } else {
            echo "No data available.";
        }
    }

    if (isset($_GET['set_rgb'])) {
        $rgb = $_GET['set_rgb'];  
        file_put_contents('rgb.txt', $rgb);
        echo "RGB set to $rgb";
    }

    if (isset($_GET['set_uv'])) {
        $uv = $_GET['set_uv']; 
        file_put_contents('uv.txt', $uv);
        echo "UV set to $uv";
    }

    if (isset($_GET['set_cooler'])) {
        $cooler = $_GET['set_cooler'];
        file_put_contents('cooler.txt', $cooler);
        echo "Cooler set to $cooler";
    }
}
?>
