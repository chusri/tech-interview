#!/home/ubuntu/wspace-2/anaconda2/bin/python

from TextGenerator import TextGenerator

def main():
    """
    Main thread of execution.

    Arguments:
    None

    Returns:
    None
    """

    text_generator = TextGenerator('republic.txt')
    text_generator.train(embedding_dim=50, lstm_mem_cells=100,
                         dense_neurons=100, epochs=100, batch_size=128)

if __name__ == '__main__':
    main()
