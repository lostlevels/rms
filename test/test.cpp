#include <bandit.h>
#include <rms.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace bandit;

#define FILENAME "myfile.txt"
#define DIRECTORY "folder"
#define CONTENTS "The quick brown fox jumps over the lazy dog."

static void createFile() {
  int fd = open(FILENAME, O_RDWR | O_CREAT, 0777);
  write(fd, CONTENTS, sizeof(CONTENTS));
  close(fd);
}

static void deleteFile() {
  unlink(FILENAME);
}

static bool fileExists() {
  return access(FILENAME, F_OK) != -1;
}

static void createDirectory() {
  mkdir(DIRECTORY, 0777);
}

static void deleteDirectory() {
  rmdir(DIRECTORY);
}

static bool directoryExists() {
  return access(DIRECTORY, F_OK) != -1;
}

go_bandit([] {
  describe("librms:", [] {

    describe("isDirectory:", [] {
      before_each([] {
        createFile();
        createDirectory();
      });

      after_each([] {
        deleteFile();
        deleteDirectory();
      });

      it("returns true if directory", [] {
        AssertThat(isDirectory(DIRECTORY), Equals(true));
      });

      it("returns false if file", [] {
        AssertThat(isDirectory(DIRECTORY), Equals(true));
      });

      it("returns false if doesn't exist.", [] {
        AssertThat(isDirectory("surely this file does not exist.foo.bar"), Equals(false));
      });
    });

    describe("isDotDirectory:", [] {
      it("returns true for dot directory", [] {
        AssertThat(isDotDirectory("."), Equals(true));
        AssertThat(isDotDirectory(".."), Equals(true));
      });

      it("returns false for hidden directory", [] {
        AssertThat(isDotDirectory(".git"), Equals(false));
      });

      it("returns false for regular directory name.", [] {
        AssertThat(isDotDirectory("myFolder"), Equals(false));
      });
    });

    describe("writeOver:", [] {
      before_each([] {
        createFile();
        AssertThat(fileExists(), Equals(true));

        char buffer[8192];
        int fd = open(FILENAME, O_RDWR);
        read(fd, buffer, sizeof(CONTENTS));
        AssertThat(strcmp(buffer, CONTENTS), Equals(0));
        close(fd);
      });

      after_each([] {
        deleteFile();
        AssertThat(fileExists(), Equals(false));
      });

      it("should write over a file", [] {
        int fd = open(FILENAME, O_RDWR);
        writeOver(fd, sizeof(CONTENTS), 512);
        lseek(fd, 0, SEEK_SET);

        char buffer[8192];
        read(fd, buffer, sizeof(CONTENTS));
        close(fd);

        AssertThat(strcmp(buffer, CONTENTS), !Equals(0));
      });
    });
  });
});

int main(int argc, char *argv[]) {
  return bandit::run(argc, argv);
}