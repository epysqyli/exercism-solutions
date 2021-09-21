<?php

function distance(string $strandA, string $strandB): int
{
    if (strlen($strandA) != strlen($strandB)) {
        throw new InvalidArgumentException('DNA strands must be of equal length.');
    }

    $hamming_distance = 0;
    $first = str_split($strandA);
    $second = str_split($strandB);
    $strands = [];

    foreach ($first as $entry) {
        $strands[] = [$entry];
    }

    foreach ($second as $key => $value) {
        $strands[$key][] = $value;
    }

    foreach ($strands as $couple) {
        if ($couple[0] != $couple[1]) {
            $hamming_distance++;
        }
    }
    return $hamming_distance;
}
