<?php

declare(strict_types=1);

class Letter
{
    public string $char;
    public int $count;

    public function __construct(string $char, int $count = 1)
    {
        $this->char = $char;
        $this->count = $count;
    }
}

function encode(string $input): string
{
    $l = strlen($input) - 1;
    $seq = [];

    // How many different subsequent letters are there?
    for ($i = 0; $i <= $l; $i++) {
        if ($i < $l) {
            if ($input[$i] != $input[$i + 1]) {
                $seq[] = new Letter($input[$i]);
            }
        } else {
            if ($input[$i - 1] != $input[$i]) {
                $seq[] = new Letter($input[$i]);
            }
        }
    }

    // Add correct count attribute to each instance
    $i = 0;
    $y = 0;

    while ($y < count($seq) & $i < $l - 1) {
        while ($input[$i] == $input[$i + 1]) {
            $seq[$y]->count++;
            $i++;
        }
        if ($input[$i] != $input[$i + 1]) {
            $i++;
        }
        $y++;
    }

    // Build encoded string
    $res = '';
    foreach ($seq as $item) {
        if ($item->count > 1) {
            $res .= $item->count . $item->char;
        } else {
            $res .= $item->char;
        }
    }

    return $res;
}

function decode(string $input): string
{
    throw new \BadFunctionCallException("Implement the decode function");
}
