<?php
interface shapes{
    public function area();
}

class rectangle implements shapes{
    public $l,$w;
    public function __construct($l,$w){
        $this->l=$l;
        $this->w=$w;
    }
    public function area(){
        echo "  qArea of rectangle : " . $this->l*$this->w;
    }
}

class square extends rectangle implements shapes{
    public $l;
    public function __construct($l){
        $this->l=$l;
    }
    public function area(){
        echo "<br>Area of Square : " . $this->l*$this->l;
    }
}

class circle implements shapes{
    public $r;
    public function __construct($r){
        $this->r=$r;
    }
    public function area(){
        echo "<br>Area of Circle : " . $this->r*$this->r;
    }
}

if($_SERVER["REQUEST_METHOD"]=="GET"){
    $rl=$_GET["rect_l"];
    $rw=$_GET["rect_w"];
    $sl=$_GET["sqr_l"];
    $r=$_GET["cir_r"];
}


$obj= new rectangle($rl,$rw);
$obj->area();
$obj= new square($sl);
$obj->area();
$obj= new circle($r);
$obj->area();
?>