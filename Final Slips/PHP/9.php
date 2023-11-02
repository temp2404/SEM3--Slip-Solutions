<?php
interface calculation{
    public function area();
    public function volume();
}

class cylinder implements calculation{
    public $PI=3.14,$r,$h;
    function __construct($r=5,$h=3){
        $this->r=$r;
        $this->h=$h;
    }
    
    function area(){
        $area=2*$this->PI*$this->r*$this->h+ 2*$this->PI*$this->r*$this->r;
        echo "Area of cylinder: ". $area . "<br>";
    }

    function volume(){
        $vol=$this->PI*$this->r*$this->r*$this->h;
        echo "Volume of cylinder: ". $vol;
    }
}

$obj = new cylinder(10,5);
echo $obj->area();
echo $obj->volume();

?>