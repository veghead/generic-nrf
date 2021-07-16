pipeline {
    agent {
        docker { image 'sesbuild:latest' }
    }
    options {
        newContainerPerStage()
    }
    stages {
        stage('Test') {
            agent {
                docker { image 'ceedrun:latest' }
            }
            steps {
                 checkout(
                    [
                        $class: 'GitSCM',
                        branches: [
                            [name: '*/main']
                        ],
                        doGenerateSubmoduleConfigurations: false, 
                        extensions: [], 
                        submoduleCfg: [], 
                        userRemoteConfigs: [
                            [
                                credentialsId: 'd7e5ac19-2c39-449f-87df-591aa533e685',
                                url: 'git@github.com:veghead/generic-nrf.git']
                            ]
                        ])
                sh '[ -e nRF5_SDK ] && rm nRF5_SDK ; ln -s /nRF_SDK nRF5_SDK && cd generic && ceedling test'
            }
        }
        stage('Build') {
            steps {

                checkout(
                    [
                        $class: 'GitSCM',
                        branches: [
                            [name: '*/main']
                        ],
                        doGenerateSubmoduleConfigurations: false, 
                        extensions: [], 
                        submoduleCfg: [], 
                        userRemoteConfigs: [
                            [
                                credentialsId: 'd7e5ac19-2c39-449f-87df-591aa533e685',
                                url: 'git@github.com:veghead/generic-nrf.git']
                            ]
                        ])
                sh '[ -e nRF5_SDK ] && rm nRF5_SDK ; ln -s /nRF_SDK nRF5_SDK && cd generic && /segger/bin/emBuild generic.emProject -config Release'
                sh 'cp generic/Output/Release/Exe/*.hex ${WORKSPACE}'
            }
        }
    }
    post {
        always {
            sh 'ls -l && /bin/pwd'
            archiveArtifacts artifacts: 'generic.hex', fingerprint: true
        }
    }
}

