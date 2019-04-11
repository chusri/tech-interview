#!/home/ubuntu/wspace-2/anaconda2/bin/python

import random
from Trie import Trie

def trie_matching(text, trie):
    """
    Match collection of patterns against the text using trie.

    Arguments:
    text -- text to be matched against the patterns
    trie -- trie containing the patterns

    Returns:
    Patterns matching the text or None if pattern not found
    """

    return [prefix_trie_matching(text[i:], trie) for i in range(len(text))]

def prefix_trie_matching(text, trie):
    """
    Match collection of patterns against the text using trie.

    Arguments:
    text -- text to be matched against the patterns
    trie -- trie containing the patterns

    Returns:
    Pattern matching the text or None if pattern not found
    """

    prefix_matches = []
    text_prefixes = generate_text_prefixes(text)

    for prefix in text_prefixes:
        if trie.search_key(prefix) is not None:
            prefix_matches.append(prefix)

    return prefix_matches

def generate_text_prefixes(text):
    """
    Generate all prefixes of text.

    Arguments:
    text -- text string

    Returns:
    All prefixes of text
    """

    return [text[:i+1] for i in range(len(text))]

def generate_text_suffixes(text):
    """
    Generate all suffixes of text.

    Arguments:
    text -- text string

    Returns:
    All suffixes of text
    """

    return [text[i:] for i in range(len(text))]

def generate_random_genome_sequences(max_sequence_length=100, max_sequences=100):
    """
    Generate random genome sequences.

    Arguments:
    max_sequence_length -- maximum length of the genome sequence
    max_sequences -- maximum number of sequences

    Returns:
    Random genome sequences
    """

    return [generate_single_random_genome_sequence(random.randint(1, max_sequence_length+1))
            for _ in range(max_sequences)]

def generate_single_random_genome_sequence(sequence_length):
    """
    Generate a single random genome sequence.

    Arguments:
    sequence_length -- length of the genome sequence

    Returns:
    Single random genome sequence
    """

    genome_alphabet = 'ACGT'
    return ''.join(random.choice(genome_alphabet) for _ in
                   range(sequence_length))

def main():
    """
    Match genome patterns with reference genome.

    Arguments:
    None

    Returns:
    None
    """

    trie = Trie(4)
    genome_sequences = generate_random_genome_sequences()

    for sequence in genome_sequences:
        trie.insert_key(sequence, len(sequence))

    for sequence in genome_sequences:
        assert(trie.search_key(sequence) == len(sequence))

if __name__ == '__main__':
    main()
