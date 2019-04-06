#!/home/ubuntu/wspace-2/anaconda2/bin/python

import random
from Trie import Trie

def generate_random_genome_sequences(max_sequence_length=100, max_sequences=100):
    """
    Generate random genome sequences.

    Arguments:
    max_sequence_length -- maximum length of the genome sequence
    max_sequences -- maximum number of sequences

    Returns:
    None
    """

    #return [for _ in range(max_sequences)]

def generate_single_random_genome_sequence(sequence_length):
    """
    Generate a single random genome sequence.

    Arguments:
    sequence_length -- length of the genome sequence

    Returns:
    single random genome sequence
    """

    genome_alphabet = 'ACGT'
    return ''.join(random.choice(genome_alphabet) for _ in
                   range(sequence_length))
