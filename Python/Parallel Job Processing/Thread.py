class Thread:
    """ This class models the thread that executes the jobs """

    def __init__(self, thread_id = 0L):
        self.thread_id = thread_id
        self.next_free_time = 0L

    def __cmp__(self, other):
        if (self.next_free_time == other.next_free_time):
            return(cmp(self.thread_id, other.thread_id))
        else:
            return(cmp(self.next_free_time, other.next_free_time))

    def get_thread_id(self):
        return(self.thread_id)

    def get_next_free_time(self):
        return(self.next_free_time)

    def set_thread_id(self, thread_id):
        self.thread_id = thread_id

    def set_next_free_time(self, next_free_time):
        self.next_free_time = next_free_time

    def info(self):
        return([self.thread_id, self.next_free_time])
