const path = require('path');
const escape = require('escape-string-regexp');
const blacklist = require('metro/src/blacklist');

const config = {
  getProjectRoots() {
    return [__dirname, path.resolve(__dirname, '..')];
  },
  getProvidesModuleNodeModules() {
    return [
      'bs-platform',
      'react-native',
      'react',
      'react-navigation',
      'reason-react',
    ];
  },
  getBlacklistRE() {
    return blacklist([
      new RegExp(
        `^${escape(path.resolve(__dirname, '..', 'node_modules'))}\\/.*$`,
      ),
    ]);
  },
};

module.exports = config;
