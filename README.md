# Generic project for Jenkins build demonstration

This is a generic nordic nrf52 SDK project.

On commit, github fires off a webhook to the CI server, which in turn
runs the pipline contained in the Jenkinsfile here.

This pipeline:

1. Runs the unit tests (all two of them) in a docker container containing all
of the required tools (ceedling, unity etc).
2. In a different docker environment, containing the segger arm build tools, it builds a release binary and archives it as an artifact. The resulting artifact is available on the build page.

Everything here from the repo to the AWS EC2 instance running Jenkins, was created solely for this task and did not exist before this week.


