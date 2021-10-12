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
            if ($i == $l && $input[$i - 1] != $input[$i]) {
                $seq[] = new Letter($input[$i]);
            } else {
                $seq[] = new Letter($input[$i]);
            }
        }
    }

    // Add correct count attribute to each instance
    $i = 0;
    $y = 0;

    while ($y < count($seq) & $i < $l - 1) {
        while ($i < $l - 1 && $input[$i] == $input[$i + 1]) {
            $seq[$y]->count++;
            $i++;
            if ($i + 1 == $l && $input[$i] == $input[$i + 1]) {
                $seq[$y]->count++;
            }
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
    preg_match_all("/[0-9]+[A-Za-z\s]|[A-Za-z\s]/", $input, $matches);

    // Build array of Letter instances
    $seq = [];

    foreach ($matches[0] as $match) {
        preg_match("/[A-Za-z\s]/", $match, $char);
        preg_match("/[0-9]+/", $match, $count);

        if (empty($count)) {
            $seq[] = new Letter($char[0]);
        } else {
            $seq[] = new Letter($char[0], (int)$count[0]);
        }
    }

    // Build return string
    $output = '';

    foreach ($seq as $item) {
        if ($item->count == 1) {
            $output .= $item->char;
        } else {
            $output .= str_repeat($item->char, $item->count);
        }
    }

    return $output;
}
