class ClusterFiles:
    def __init__(self, numfiles):
        self.numfiles = numfiles
        self.files = dict()

    def __enter__(self):
        for num in range(self.numfiles):
            print("Opening file " + str(num))
            f = open("cluster"+str(num), "a")
            self.files[num] = f
        return self

    def __exit__(self, *args):
        for num, file in self.files.items():
            print("Closing file " + str(num))
            file.close()

with ClusterFiles(5) as cf:
    print("Jagan")