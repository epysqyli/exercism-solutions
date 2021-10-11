<?php

declare(strict_types=1);

function encode(string $input): string
{
    // Data structure: array of Letter instances with char and count?
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

    $str = 'AAABDDDCCCEEA';
    $l = strlen($str) - 1;
    $seq = [];

    // How many different subsequent letters are there?
    for ($i = 0; $i <= $l; $i++) {
        if ($i < $l) {
            if ($str[$i] != $str[$i + 1]) {
                $uniqueSeq[] = $str[$i];
                $seq[] = new Letter($str[$i]);
            }
        } else {
            if ($str[$i - 1] != $str[$i]) {
                $seq[] = new Letter($str[$i]);
            }
        }
    }

    // Add correct count attribute to each instance
    $i = 0;
    $y = 0;

    while ($y < count($seq) & $i < $l - 1) {
        while ($str[$i] == $str[$i + 1]) {
            $seq[$y]->count++;
            $i++;
        }
        if ($str[$i] != $str[$i + 1]) {
            $i++;
        }
        $y++;
    }

    return 'string';
}

function decode(string $input): string
{
    throw new \BadFunctionCallException("Implement the decode function");
}
