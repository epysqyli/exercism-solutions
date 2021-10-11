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
    $uniqueSeq = [];
    $i = 0;

    // How many different subsequent letters are there?
    while ($i <= $l) {
        if ($i < $l) {
            if ($str[$i] != $str[$i + 1]) {
                $uniqueSeq[] = $str[$i];
            }
        } else {
            if ($str[$i - 1] != $str[$i]) {
                $uniqueSeq[] = $str[$i];
            }
        }

        $i++;
    }

    return 'string';
}

function decode(string $input): string
{
    throw new \BadFunctionCallException("Implement the decode function");
}
