pipeline {
    agent {
        docker { image 'ceedrun:latest' }
    }
    stages {
        stage('Test') {
            steps {
                sh 'ceedling test'
            }
        }
    }
}
